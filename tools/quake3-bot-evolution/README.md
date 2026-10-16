# Quake III Bot Evolution — Tooling

Artefakte aus der Arbeit an der Bot-Interbreeding-Pipeline (ioquake3 Fork).

## Inhalt

- `q3_mcp_server.py` — MCP-Server (stdio) für den Q3-Server: RCON, Bot-Steuerung,
  Interbreeding-Trigger, Log-Tail. MCP-SDK v2 (\`mcp.server.mcpserver.MCPServer\`).
  Registrierung: \`mcporter config add quake3 --stdio "..."\`
- `sv_cheats_rom.patch` — Entfernt das \`CVAR_ROM\`-Flag von \`sv_cheats\`
  (code/server/sv_init.c), damit die cheat-protected Interbreeding-Cvars
  (bot_interbreedchar/bots/cycle/write) per RCON/Live-Konsole setzbar werden.

## Kern-Patches (Branch \`bot-evolution\`)

1. **Botlib-Writer reaktiviert** (Commit \`c719e91\`):
   \`be_ai_weight.c\` Writer von raw \`fopen()/fprintf()\` auf
   \`botimport.FS_FOpenFile(FS_WRITE)\` + \`FS_Write()\` umgeschrieben;
   \`BotSaveGoalFuzzyLogic()\` in \`be_ai_goal.c\` reaktiviert.
   Damit kann \`bot_interbreedwrite\` evolvierte Gewichtungen persistieren.

2. **sv_cheats ROM-Flag entfernt** (\`sv_cheats_rom.patch\`):
   Interbreeding-Cvars sind \`CVAR_CHEAT\` und brauchen \`sv_cheats 1\`.
   Ohne diesen Patch ist der gesamte Pfad auf geharteten ioq3-Binaries gesperrt.

## Bekanntes Problem (offen)

Bei \`ClientBegin\` des ersten Bots crasht der Server mit
\`Bad game system trap: 425\` — reproduzierbar in QVM- *und* DLL-Modus,
mit und ohne obige Patches. Trap 425 liegt außerhalb des ioq3-Trap-Enums
(max \`BOTLIB_PC_SOURCE_FILE_AND_LINE\` = 336), tritt also in einem
Engine-Trap-Dispatch-Pfad auf, der von der Bot-Charakter-Initialisierung
getriggert wird. Noch nicht lokalisiert.

## Umgebung

- Build: ioquake3 trunk \`87a99d1\` + obige Patches, CMake/Ninja
- Modus: \`g_gametype 1\` (FFA), \`bot_minplayers 2\`, Map \`q3tourney2\`
- Assets: pak0 (id-Software) + pak1–8
