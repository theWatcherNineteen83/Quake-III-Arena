# Quake III Bot Evolution — Tooling & Dokumentation

Genetische Bot-Evolution für ioquake3: Bots kämpfen gegeneinander, die besten
Fuzzy-Logic-Gewichte werden automatisch als neue `.c`-Datei geschrieben und können
im nächsten Match geladen werden.

## Status

**v0.1-bot-evolution-working** (Tag `v0.1-bot-evolution-working`, Commit `27d6c21`)
Erster funktionierender End-to-End-Durchlauf: 4 Grunt-Bots kämpfen auf q3dm1,
Match endet bei Fraglimit, evolvierte Gewichtungstabelle wird nach
`bots/evolved_grunt.c` geschrieben (893 Zeilen, ~17 KB).

## Was wurde angepasst

### Kern-Patches (Branch `bot-evolution`, 16 Commits über Upstream)

| Bereich | Änderung | Warum |
|---|---|---|
| **Botlib-Writer** | `WriteWeightConfig()` in `be_ai_weight.c` von raw `fopen()/fprintf()` auf `botimport.FS_FOpenFile(FS_WRITE)` + `FS_Write()` umgeschrieben; `BotSaveGoalFuzzyLogic()` in `be_ai_goal.c` reaktiviert | Original-Code war deaktiviert — evolvierte Gewichte konnten nicht persistiert werden |
| **Cvar-Handling** | CVAR_SYSTEMINFO für alle Interbreeding-Cvars; `trap_Cvar_Update()` vor Cycle-Check; Force-Set in `G_InitGame` | Cvars waren per `+set` nicht sichtbar im Game-Modul |
| **Timing-Guards** | `numbots==0` Guard; One-Shot gegen Dauerfeuer; `bot_interbreedmatchcount` Reset | `BotInterbreeding()` feuerte vor Bot-Load oder jeden Frame |
| **CTF-Combat** | Bot-Kampflogik in `ai_dmq3.c` für CTF/Team/Harvester aktiviert | Bots kämpften nur in FFA, ignorierten Gegner in Team-Modes |
| **bestbot-Threshold** | Initialwert `bestrank` von `0` auf `-999` geändert | In DM hatten alle Bots negative Scores (mehr Deaths als Kills) → kein Bot ausgewählt → Schreiben übersprungen |
| **sv_cheats** | CVAR_ROM-Flag entfernt (`sv_cheats_rom.patch`); CVAR_CHEAT von Interbreeding-Cvars entfernt | Cheat-protected Cvars waren auf gehärteten Binaries nicht per RCON setzbar |
| **Multi-Cycle** | `bot_interbreedchar` wird nach Zyklus nicht mehr auf leer zurückgesetzt | Zweiter Evolution-Zyklus konnte nie starten |

### Dateien geändert

```
code/botlib/be_ai_goal.c       — BotSaveGoalFuzzyLogic reaktiviert
code/botlib/be_ai_weight.c     — WriteWeightConfig auf FS-API portiert
code/game/ai_dmq3.c            — CTF/Team-Combat für Bots
code/game/ai_main.c            — Interbreeding-Logik, Guards, Debug-Logging
code/qcommon/cvar.c            — CVAR_SYSTEMINFO Support
code/server/sv_bot.c           — Cvar-Registrierung, CVAR_CHEAT entfernt
code/server/sv_ccmds.c         — sv_cheats ROM-Flag entfernt
tools/quake3-bot-evolution/    — MCP-Server, Patches, diese README
```

## Welcher Bot

Aktuell **Grunt** (Standard-Q3-Bot, Skill 4). Die Evolution schreibt
`evolved_grunt.c` mit angepassten Fuzzy-Logic-Gewichten für Item-Prioritäten,
Waffenwahl und Kampfverhalten.

Andere Bots (Sarge, Visor, Ranger, etc.) sind technisch möglich — einfach
`bot_interbreedchar` auf den gewünschten Bot-Namen setzen. Noch nicht getestet.

Die evolvierte Datei enthält Gewichtstabellen wie:
```
weight "item_armor_shard"
{
    switch(41) {
        case 1: {
            switch(1) {
                case 10: return balance(20,0,50);
                ...
```

## Unterstützte Spielmodi

Alle Modi werden durch Gametype-Erkennung in `BotInterbreeding()` unterstützt:

| Modus | g_gametype | Status |
|---|---|---|
| **Free For All (DM)** | 0 | ✅ Getestet und funktioniert |
| **Tournament (1v1)** | 1 | ✅ Code-Pfad vorhanden, nicht separat getestet |
| **Team Deathmatch** | 3 | ✅ CTF-Combat-Fix aktiviert Team-Kampf |
| **Capture The Flag** | 4 | ✅ CTF-Combat-Fix aktiviert Flag-Verhalten + Kampf |
| **One Flag CTF** | 5 | ✅ Code-Pfad vorhanden |
| **Harvester** | 6 | ✅ Code-Pfad vorhanden |
| **Single Player** | 2 | ⚠️ Lädt nur Arena-spezifische Bots, nicht geeignet |

**Empfehlung:** FFA (g_gametype 0) mit `devmap <mapname>` für erste Tests.
Map-Empfehlungen: `q3dm1` (Arena Gate), `q3dm6` (Campgrounds). Vermeide `q3dm17`
(Abgründe → Bots fallen raus).

## MCP-Schnittstelle

### Übersicht

Stdio-basierter MCP-Server für OpenClaw / Claude Desktop / Cursor.
Läuft auf demselben Host wie `ioq3ded` und steuert den Server per RCON.

### Installation & Start

```bash
# Abhängigkeiten
pip install mcp

# Umgebungsvariablen
export Q3_RCON_HOST=127.0.0.1
export Q3_RCON_PORT=27960
export Q3_RCON_PASSWORD=prombot2026
export Q3_LOG_PATH=/tmp/q3test.log
export Q3_BOTFILES_DIR=/home/prometheus/q3home/baseq3/bots

# Starten (stdio-Transport)
python3 tools/quake3-bot-evolution/q3_mcp_server.py
```

### Registrierung in OpenClaw

```bash
mcporter config add quake3 --stdio "python3 /path/to/q3_mcp_server.py"
```

### Verfügbare Tools

| Tool | Beschreibung |
|---|---|
| `q3_rcon(command)` | Beliebigen RCON-Befehl senden |
| `q3_status()` | Server-Status: Bots, Score, Map, Gametype |
| `q3_addbot(name, skill, team)` | Bot hinzufügen (Name, Skill 1-5, Team) |
| `q3_interbreed_start(character, bots, cycle, write_name)` | Evolution-Zyklus starten (injiziert Cvars live) |
| `q3_interbreed_status(write_name)` | Prüfen ob evolvierte Dateien geschrieben wurden |
| `q3_log_tail(lines)` | Letzte N Zeilen des Server-Logs |
| `q3_map_restart()` | Map neu starten (triggert ExitLevel → EndMatch) |
| `q3_cvar_get(name)` | Cvar-Wert abfragen |
| `q3_cvar_set(name, value)` | Cvar setzen |

### Typischer Workflow

```
1. q3_status()                          → Server läuft?
2. q3_addbot("grunt", 4) × 4           → 4 Bots hinzufügen
3. q3_interbreed_start("grunt", 4, 1)   → Evolution aktivieren
4. [Match läuft bis Fraglimit]
5. q3_interbreed_status("evolved_grunt") → Datei geschrieben?
6. q3_log_tail(20)                      → Debug-Infos prüfen
```

## Quickstart: Evolution testen

### Voraussetzungen

- ioquake3 Build vom Branch `bot-evolution`
- Q3-Assets (pak0-pak8.pk3)
- Linux oder Windows

### Server starten

```bash
./ioq3ded \
  +set fs_basepath "/path/to/quake3" \
  +set fs_homepath "/path/to/q3home" \
  +set sv_pure 0 \
  +set sv_cheats 1 \
  +set fraglimit 10 \
  +set bot_enable 1 \
  +set bot_interbreedcycle 1 \
  +set bot_interbreedchar grunt \
  +set bot_interbreedbots 4 \
  +set bot_interbreedwrite "bots/evolved_grunt.c" \
  +set rconpassword prombot2026 \
  +devmap q3dm1
```

### Bots per RCON hinzufügen

```bash
# 4 Grunt-Bots hinzufügen
for i in 1 2 3 4; do
  printf '\xff\xff\xff\xffrcon prombot2026 addbot grunt 4\n' | nc -u -w1 127.0.0.1 27960
  sleep 1
done
```

### Ergebnis prüfen

Nach Match-Ende (fraglimit erreicht):
```bash
ls -la $Q3_HOME/baseq3/bots/evolved_grunt.c
# Erwartet: ~17KB, ~893 Zeilen Fuzzy-Logic-Gewichten
```

## Bekannte Einschränkungen

- **Debug-Logging noch aktiv:** `DEBUG-ENDMATCH` und `DEBUG-WRITE` Ausgaben im Log (sollten vor Production entfernt werden)
- **Bots per RCON hinzufügen:** `G_InitBots()` lädt in DM keine Bots automatisch → Workaround via RCON `addbot`
- **Nur Goal-Fuzzy-Logic:** Aktuell wird nur `itemweightconfig` geschrieben, nicht Weapon- oder Chat-Gewichte
- **Single Player ungeeignet:** GT=2 lädt nur Arena-spezifische Bots, nicht den gewünschten Evolution-Charakter

## Umgebung

- **Build:** ioquake3 trunk `87a99d1` + bot-evolution Patches, CMake/Ninja
- **Getestet auf:** Linux (miniedi, Ubuntu/Debian) und Windows (GSM-PC)
- **Assets:** pak0 (id Software) + pak1–8
- **Maps:** q3dm1, q3dm6 empfohlen
