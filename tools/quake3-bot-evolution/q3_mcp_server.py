#!/usr/bin/env python3
"""Quake 3 MCP Server — RCON + Log-Tail + Bot-Steuerung + Interbreeding-Trigger.

Stdio-Transport für OpenClaw / Claude Desktop / Cursor.
Läuft auf miniedi neben ioq3ded.

Tools:
  - q3_rcon: beliebigen RCON-Befehl senden
  - q3_status: Server-Status (Bots, Score, Map)
  - q3_addbot: Bot hinzufügen (Name, Skill, Team)
  - q3_interbreed_start: Interbreeding-Zyklus starten (injiziert bot_interbreedchar)
  - q3_interbreed_status: Prüfen ob evolved-Dateien geschrieben wurden
  - q3_log_tail: Letzte N Zeilen des Server-Logs
  - q3_map_restart: Map neu starten
  - q3_cvar_get: Cvar-Wert abfragen
  - q3_cvar_set: Cvar setzen
"""

import os
import socket
import struct
from pathlib import Path

from mcp.server.mcpserver import MCPServer

# --- Config ---
RCON_HOST = os.environ.get("Q3_RCON_HOST", "127.0.0.1")
RCON_PORT = int(os.environ.get("Q3_RCON_PORT", "27960"))
RCON_PASSWORD = os.environ.get("Q3_RCON_PASSWORD", "changeme")
LOG_PATH = os.environ.get("Q3_LOG_PATH", "/tmp/q3runM.log")
BOTFILES_DIR = os.environ.get("Q3_BOTFILES_DIR", "/tmp/q3test/baseq3/bots")

mcp = MCPServer(
    name="quake3-bot-evolution",
    instructions="MCP interface for Quake 3 server with bot interbreeding/evolution support. "
                 "Use q3_interbreed_start to trigger the genetic algorithm during a running match.",
)


def _rcon_send(command: str, timeout: float = 5.0) -> str:
    """Send RCON command via UDP and return response."""
    payload = f"\xff\xff\xff\xffrcon {RCON_PASSWORD} {command}"
    data = struct.pack("<I", len(payload)) + payload.encode("latin-1")

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.settimeout(timeout)
    try:
        sock.sendto(data, (RCON_HOST, RCON_PORT))
        response_parts = []
        while True:
            try:
                resp_data, _ = sock.recvfrom(4096)
                text = resp_data.decode("latin-1", errors="replace")
                text = text.replace("\xff\xff\xff\xff", "")
                if text.startswith("print\n"):
                    text = text[6:]
                elif text.startswith("print"):
                    text = text[5:]
                response_parts.append(text.strip())
            except socket.timeout:
                break
        return "\n".join(response_parts).strip()
    except socket.timeout:
        return "(timeout — no response from server)"
    except ConnectionRefusedError:
        return "(connection refused — server not running?)"
    finally:
        sock.close()


@mcp.tool()
def q3_rcon(command: str) -> str:
    """Send an arbitrary RCON command to the Quake 3 server.

    Args:
        command: The console command to execute (e.g., "status", "map q3tourney2", "addbot grunt 4")
    """
    return _rcon_send(command)


@mcp.tool()
def q3_status() -> str:
    """Get current server status: connected players/bots, scores, map, gametype."""
    return _rcon_send("status")


@mcp.tool()
def q3_addbot(name: str, skill: int = 4, team: str = "", delay: int = 0, altname: str = "") -> str:
    """Add a bot to the running game.

    Args:
        name: Bot character name (e.g., "grunt", "sarge", "visor")
        skill: Skill level 1-5 (default 4)
        team: Team for team games ("red"/"blue"), empty for FFA/Tournament
        delay: Respawn delay in ms
        altname: Alternative display name
    """
    cmd = f"addbot {name} {skill}"
    if team:
        cmd += f" {team}"
    if delay:
        cmd += f" {delay}"
    if altname:
        cmd += f" {altname}"
    return _rcon_send(cmd)


@mcp.tool()
def q3_interbreed_start(character: str = "grunt", bots: int = 2, cycle: int = 1, write_name: str = "grunt_evolved") -> str:
    """Start the bot interbreeding/genetic evolution cycle DURING a running match.

    This is the key tool: it injects the interbreeding cvars into the live server,
    which triggers BotInterbreeding() in the next BotAIStartFrame(). Without this
    runtime injection, startup +set args never activate the interbreeding path.

    Args:
        character: Base bot character to evolve (default "grunt")
        bots: Number of bots to use for interbreeding (default 2)
        cycle: Number of matches before writing evolved weights (default 1)
        write_name: Output filename prefix for evolved bot (default "grunt_evolved")
    """
    results = []
    results.append(f"Setting interbreeding cvars on live server...")

    cvars = [
        f"bot_interbreedchar {character}",
        f"bot_interbreedbots {bots}",
        f"bot_interbreedcycle {cycle}",
        f"bot_interbreedwrite {write_name}",
    ]
    for cv in cvars:
        resp = _rcon_send(cv)
        results.append(f"  {cv} → {resp or 'OK'}")

    _rcon_send("bot_minplayers 0")
    results.append("  bot_minplayers set to 0 (prevents server-side auto-addbot interference)")

    results.append("")
    results.append(f"Interbreeding armed. After {cycle} completed tournament match(es),")
    results.append(f"evolved weights will be written to: {BOTFILES_DIR}/{write_name}_i.c and _w.c")
    results.append("")
    results.append("Use q3_interbreed_status to check progress.")

    return "\n".join(results)


@mcp.tool()
def q3_interbreed_status(write_name: str = "grunt_evolved") -> str:
    """Check whether evolved bot files have been written to disk.

    Args:
        write_name: The output filename prefix used in q3_interbreed_start (default "grunt_evolved")
    """
    botdir = Path(BOTFILES_DIR)
    results = []

    i_file = botdir / f"{write_name}_i.c"
    w_file = botdir / f"{write_name}_w.c"

    results.append(f"Checking for evolved files in {BOTFILES_DIR}/:")
    results.append(f"  {write_name}_i.c: {'EXISTS (' + str(i_file.stat().st_size) + ' bytes)' if i_file.exists() else 'not yet'}")
    results.append(f"  {write_name}_w.c: {'EXISTS (' + str(w_file.stat().st_size) + ' bytes)' if w_file.exists() else 'not yet'}")

    log_path = Path(LOG_PATH)
    if log_path.exists():
        log_text = log_path.read_text(errors="replace")
        interbreed_lines = [l for l in log_text.splitlines() if "interbreed" in l.lower() or "BotWrite" in l or "couldn't open" in l]
        if interbreed_lines:
            results.append("")
            results.append("Relevant log entries:")
            for line in interbreed_lines[-10:]:
                results.append(f"  {line}")
        else:
            results.append("")
            results.append("No interbreeding-related log entries found yet.")

    status = _rcon_send("bot_interbreedmatchcount")
    results.append(f"\nServer cvar bot_interbreedmatchcount: {status}")

    return "\n".join(results)


@mcp.tool()
def q3_log_tail(lines: int = 50) -> str:
    """Read the last N lines of the Quake 3 server log.

    Args:
        lines: Number of lines to read from end of log (default 50)
    """
    log_path = Path(LOG_PATH)
    if not log_path.exists():
        return f"Log file not found: {LOG_PATH}"

    content = log_path.read_text(errors="replace")
    all_lines = content.splitlines()
    tail = all_lines[-lines:]
    return "\n".join(tail)


@mcp.tool()
def q3_map_restart() -> str:
    """Restart the current map (triggers ExitLevel → BotInterbreedEndMatch if interbreeding is active)."""
    return _rcon_send("map_restart")


@mcp.tool()
def q3_cvar_get(name: str) -> str:
    """Get the current value of a server cvar.

    Args:
        name: Cvar name (e.g., "g_gametype", "fraglimit", "bot_interbreedchar")
    """
    return _rcon_send(name)


@mcp.tool()
def q3_cvar_set(name: str, value: str) -> str:
    """Set a server cvar to a new value.

    Args:
        name: Cvar name
        value: New value
    """
    return _rcon_send(f"{name} {value}")


if __name__ == "__main__":
    mcp.run(transport="stdio")
