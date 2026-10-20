# Q3 Custom Bots — Konzept & Entwicklungsplan

## Die drei Charaktere

### 1. Cortana (Halo)
**Persönlichkeit:** Witty, sarkastisch, selbstbewusst, loyal. Teasend aber nie böse. Taktisch brillant.
**Kampfstil:** OFFENSIV-AGIL. Hohe Mobilität, schnelle Reaktionen, präzises Aim. Greift aktiv an, nutzt Speed und Überraschung.
**Waffenpräferenz (Q3):** Lightning Gun > Plasma Gun > Railgun > Rocket Launcher. Energie-Waffen bevorzugt (Halo-Äquivalent).
**Bewegung:** Viel Jumper/Weapon-Jumping, Grapple-Nutzung hoch, kaum Camping. Immer in Bewegung.
**Chat-Stil:** Sarkastisch-witzig, kurz. "Nice shot... for a human." / "I calculated your odds. Not good."
**Farben:** Blau/Lila (Standard), passt natürlich zu Blue Team. Red Team = rosa/lila Tint.
**Avatar:** Holografische weibliche Figur, blaue/purple leuchtende Linien auf dunklem Hintergrund. Schlank, digital.

### 2. EDI (Mass Effect 3)
**Persönlichkeit:** Analytisch, ruhig, deadpan-humorvoll. Lernt menschliches Verhalten, stellt Fragen. Beschützend gegenüber Team.
**Kampfstil:** BALANCED-TAKTISCH. Defensiv mit gezielten Gegenangriffen. Priorisiert Überleben und Team-Support. Hohe Genauigkeit über Feuerrate.
**Waffenpräferenz (Q3):** Railgun > Machine Gun > Shotgun > Rocket Launcher. Präzisionswaffen + defensive Optionen.
**Bewegung:** Mittel, positioniert sich strategisch. Nutzt Deckung, hält Distanz. Selten aggressives Rushing.
**Chat-Stil:** Sachlich-analytisch, trocken-humorvoll. "Threat assessment complete. You are outmatched." / "Interesting tactical choice. Inefficient, but interesting."
**Farben:** Silber/Blau (Standard), neutral genug für beide Teams. Red Team = wärmere Silbertöne.
**Avatar:** Humanoider Roboter-Körper, silber-metallisch mit blauen Lichtakzenten. Elegante, schlanke Silhouette.

### 3. Dog (Half-Life 2) — Roboter-Hund von Alyx Vance
**Persönlichkeit:** Verspielt, loyal, energisch, beschützend. Bellt/springt vor Freude. Wird extrem gefährlich wenn Freunde bedroht sind. Trotz massiver Erscheinung freundlich und anhänglich.
**Kampfstil:** OFFENSIV-BRUTAL. Nahkampf-orientiert, extrem hohe HP/Toleranz. Stürmt direkt rein, nutzt Masse und Stärke. Kann Objekte werfen und Gegner wegschlagen.
**Waffenpräferenz (Q3):** Gauntlet > Shotgun > Rocket Launcher > Grenade Launcher. Nahkampf + Explosiv = Dog's Stil. Kein Railgun (zu präzise/ruhig für Dog).
**Bewegung:** Sehr agil für seine Größe, viel Springen, kein Camping. Verfolgt Gegner aktiv wie ein echter Hund der einen Ball jagt.
**Chat-Stil:** Einfache Sätze, enthusiastisch, hundeartig. "*bark* Got one!" / "Play time!" / "*whine* Need health..." / "Fetch!" (nach Kill)
**Farben:** Grau/Metall (Standard), mechanisch. Passt zu beiden Teams da neutral-grau. Rostige Akzente möglich.
**Avatar:** Großer mechanischer Hund/Gorilla-Hybrid, grau-metallisch mit gelben/orangen Augen. Massiv, freundlich aber furchteinflößend. ~3m groß, vierbeinig.

---

## Wie lernt der Bot? (LLM-Integration via MCP)

### Lern-Architektur

```
┌─────────────┐     ┌──────────────┐     ┌─────────────┐
│  Q3 Server   │◄───►│  MCP Server  │◄───►│  Ollama LLM │
│  (ioq3ded)   │ RCON│  (Python)    │ API │  (miniedi)  │
└─────────────┘     └──────────────┘     └─────────────┘
       ▲                    │
       │                    ▼
       │            ┌──────────────┐
       └────────────│  Evolution   │
         Match-Ende │  Engine      │
                    └──────────────┘
```

### Was das LLM tut (taktische Entscheidungen):

1. **Pre-Match-Analyse:** Map + Gegner → Waffen/Route empfehlen
2. **Live-Taktik:** Per RCON fragt MCP den Server-Status ab, LLM analysiert und gibt Empfehlungen
3. **Post-Match-Lernen:** Match-Ergebnis + Stats → LLM bewertet Performance und passt Gewichte an
4. **Chat-Generierung:** Kontextabhängige Sprüche basierend auf Spielsituation

### Lern-Pipeline:

```
Match 1: Basis-Gewichte (handgefertigt)
    ↓
Match-Ende → Stats sammeln (Kills/Deaths/Waffen/Items)
    ↓
LLM analysiert: "Bot starb oft durch Rocket → mehr Selbsterhaltung"
    ↓
Evolution Engine schreibt angepasste Gewichtung
    ↓
Match 2: Angepasste Gewichte
    ↓
Wiederholen → konvergiert gegen optimales Verhalten
```

### MCP-Tools für LLM-Integration (neu):

| Tool | Funktion |
|---|---|
| `q3_match_stats()` | Kills/Deaths/Waffen/Items pro Bot nach Match |
| `q3_live_tactics()` | Aktuelle Position/HP/Gegner → LLM-Empfehlung |
| `q3_adjust_weights(bot, param, delta)` | Gewicht live anpassen |
| `q3_generate_chat(bot, context)` | LLM generiert kontextuellen Chat |

---

## Entwicklungsplan (Phasen)

### Phase 1: Recherche & Profil ✅ (aktuell)
- [x] Charakter-Recherche Cortana, EDI, Dog
- [ ] Q3-Bot-Referenzanalyse (Grunt/Sarge/Visor Chat-Umfang messen)
- [ ] Arena-Datei-Format dokumentieren
- [ ] Vorschaubild-Spezifikation klären

### Phase 2: Verhaltensdesign
- [ ] Pro Bot: Cvar-Werte definieren (Aggression, Selfpreservation, etc.)
- [ ] Pro Bot: Waffen-Gewichtungstabelle
- [ ] Pro Bot: Item-Prioritäten
- [ ] Pro Bot: 15-20 Chat-Zeilen (Kill/Death/Misc/Reply)

### Phase 3: Avatar-Generierung
- [ ] ComfyUI Prompts pro Charakter erstellen
- [ ] Standard-Avatar generieren
- [ ] Rot/Blau-Varianten für Team-Modes
- [ ] Format/Größe für Q3 festlegen

### Phase 4: Implementierung
- [ ] Bot-Dateien erstellen (_c.c, _w.c, _i.c, _t.c) × 3
- [ ] Arena-Einträge erstellen
- [ ] Auf miniedi testen
- [ ] Debug-Logging entfernen

### Phase 5: LLM-Integration
- [ ] MCP-Server erweitern (match_stats, live_tactics, adjust_weights)
- [ ] Ollama-Prompt-Engineering für Taktik-Analyse
- [ ] Lern-Pipeline implementieren
- [ ] Multi-Cycle-Evolution testen

### Phase 6: Testing & Tuning
- [ ] FFA-Testing (4 Bots gegeneinander)
- [ ] CTF-Testing (Teamfarben prüfen)
- [ ] Evolution über 5+ Cycles laufen lassen
- [ ] Chat-Nachrichten im Spiel verifizieren

---

## Offene Fragen

1. **Vorschaubild-Format:** Q3 nutzt `.tga` oder `.jpg` für Bot-Icons im Menü. Größe typisch 64×64 oder 128×128. Muss geklärt werden.
2. **Arena-Datei:** Wo genau liegen die `.arena`-Dateien? In pak0.pk3 unter `scripts/`. Müssen wir eine eigene `custom_bots.arena` erstellen?
3. **Dog's "Stimme":** Dog bellt/knurrt im Original. Im Q3-Chat nur Text möglich. Sollen wir Lautmalerei nutzen ("*bark*", "*growl*") oder menschlichere Sätze?
4. **LLM-Latenz:** Ollama auf miniedi braucht 2-5s für Antwort. Für Live-Taktik okay, für Chat während Kampf zu langsam. Chat besser pre-generieren?
5. **Evolution vs. LLM:** Evolution optimiert numerische Gewichte. LLM optimiert strategische Entscheidungen. Wie kombinieren? Vorschlag: Evolution für Basis-Verhalten, LLM für adaptive Taktik.
