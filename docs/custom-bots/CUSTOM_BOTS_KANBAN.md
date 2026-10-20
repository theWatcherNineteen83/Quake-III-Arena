# Custom Q3 Bots — Kanban Board

## 🎯 Ziel
3 Custom-Bots für Quake 3: Cortana (Halo), EDI (Mass Effect 3), Dog (Half-Life 2).
Mit LLM-gestütztem Lernen via MCP, handgefertigter Basis + Evolution-Optimierung.

---

## 📋 BACKLOG

### Charakter-Design
- [ ] Cortana: Vollständiges Verhaltensprofil (Waffen, Bewegung, Chat)
- [ ] EDI: Vollständiges Verhaltensprofil
- [ ] Dog: Vollständiges Verhaltensprofil

### Q3-Technik
- [ ] Arena-Datei-Format dokumentieren
- [ ] Vorschaubild-Spezifikation klären (Format, Größe, Pfad)
- [ ] Teamfarben-Mechanik verstehen (rot/blau Tint)

### Implementierung
- [ ] Bot-Dateien erstellen (_c.c, _w.c, _i.c, _t.c) × 3
- [ ] Arena-Einträge erstellen
- [ ] Avatare generieren (ComfyUI) + Rot/Blau-Varianten
- [ ] Auf miniedi testen

### LLM-Integration
- [ ] MCP-Server erweitern (match_stats, live_tactics, adjust_weights)
- [ ] Ollama-Prompt-Engineering für Taktik-Analyse
- [ ] Lern-Pipeline: Basis → Match → LLM-Analyse → Evolution
- [ ] Multi-Cycle-Evolution testen

---

## 🔧 IN PROGRESS

### Phase 3: Verhaltensdesign
- [ ] Cortana: Cvar-Werte + Waffen-Gewichtung + Item-Prioritäten + 15-20 Chat-Zeilen
- [ ] EDI: Cvar-Werte + Waffen-Gewichtung + Item-Prioritäten + 15-20 Chat-Zeilen
- [ ] Dog: Cvar-Werte + Waffen-Gewichtung + Item-Prioritäten + 15-20 Chat-Zeilen
- [ ] Avatar-Prompts für ComfyUI erstellen

## ✅ DONE

### Phase 2: Q3-Referenzanalyse
- [x] Chat-Dateien: ~250-290 Zeilen/Bot, 27 Typen (kill/death/enter/exit/level/insult/misc)
- [x] Chat-Struktur: `chat "name" { type "xxx" { "msg"; } }` + shared rnd.c/rchat.c/syn.c
- [x] Arena-Format: .arena = Maps, nicht Bots. Bots via addbot oder bots.txt
- [x] Bot-Icons: `models/players/heads/<name>/icon_default.tga` + icon_red.tga + icon_blue.tga
- [x] Teamfarben: Separate Skin-Dateien icon_red.tga / icon_blue.tga pro Modell

---

## ✅ DONE

### Phase 1: Charakter-Recherche & Q3-Technik
- [x] Cortana (Halo): Halopedia + Halo Wiki → witty, sarkastisch, taktisch brillant, offensiv-agil
- [x] EDI (Mass Effect 3): ME Wiki + Fextralife → analytisch, deadpan-humorvoll, balanced-taktisch
- [x] Dog (Half-Life 2): HL Wiki + Robot Wiki → verspielt, loyal, offensiv-brutal, nahkampf
- [x] Konzept-Dokument erstellt (BOT_CONCEPT.md)
- [x] User-Entscheidungen: LLM=taktisch, Basis→Lernen, kurze Sprüche, Dog=Roboter-Hund
- [x] Q3-Chat: 27 Typen, ~260 Zeilen, Struktur mit rnd.c/rchat.c/syn.c
- [x] Q3-Icons: icon_default.tga + icon_red.tga + icon_blue.tga
- [x] Q3-Arena: Maps only, Bots via addbot/bots.txt

---

## 📊 METRIKEN
- **Letzte Aktualisierung:** 2026-10-20 22:15
- **Nächster Meilenstein:** Phase 2 abgeschlossen → Verhaltensdesign starten
- **Blocker:** Keine
