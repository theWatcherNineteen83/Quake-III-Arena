# Custom Q3 Bots — Cortana, EDI, Dog

## Übersicht
Drei charakterbasierte Bots für Quake 3 Arena mit einzigartigen Persönlichkeiten, Kampfverhalten und Chat-Stilen.

| Bot | Quelle | Stil | Geschlecht |
|---|---|---|---|
| **Cortana** | Halo | Offensiv-Agil, sarkastisch-witzig | Female |
| **EDI** | Mass Effect 3 | Balanced-Taktisch, analytisch-deadpan | Female |
| **Dog** | Half-Life 2 | Offensiv-Brutal, hundeartig-enthusiastisch | Male |

## Dokumente
- `BOT_CONCEPT.md` — Gesamtkonzept, Lern-Architektur, LLM-Integration
- `BOT_PROFILES.md` — Vollständige Verhaltensprofile (Cvars, Waffen, Items, Chat)
- `CUSTOM_BOTS_KANBAN.md` — Entwicklungsboard (Backlog/In Progress/Done)

## Bot-Dateien
```
code/game/botfiles/custom/
├── cortana_c.c    # Charakter-Cvars + Waffen + Items
├── cortana_w.c    # Waffen-Gewichtungstabelle
├── cortana_i.c    # Item-Prioritätstabelle
├── edi_c.c        # Charakter-Cvars + Waffen + Items
├── edi_w.c        # Waffen-Gewichtungstabelle
├── edi_i.c        # Item-Prioritätstabelle
├── dog_c.c        # Charakter-Cvars + Waffen + Items
├── dog_w.c        # Waffen-Gewichtungstabelle
└── dog_i.c        # Item-Prioritätstabelle
```

## Status
- ✅ Phase 1: Charakter-Recherche
- ✅ Phase 2: Q3-Referenzanalyse
- ✅ Phase 3: Verhaltensdesign
- ⏳ Phase 4: Implementierung (Chat-Dateien `_t.c` fehlen noch)
- ⏳ Phase 5: Avatar-Generierung
- ⏳ Phase 6: Testing & Evolution

## Nächste Schritte
1. Chat-Dateien (`_t.c`) für alle drei Bots erstellen
2. Arena-Einträge / `bots.txt` anpassen
3. Avatare via ComfyUI generieren (Rot/Blau-Varianten)
4. Auf miniedi testen
5. Evolution-Zyklen starten
