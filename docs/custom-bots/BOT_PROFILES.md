# Bot-Verhaltensprofile — Cortana, EDI, Dog

## Referenz: Grunt (Baseline)
- Aggression: 0.5 | Selfpreservation: 0.75 | Vengefulness: 0.5 | Camper: 0.75
- Attack Skill: 0.4 (skill1) / 0.75 (skill4)
- Aim Skill: 0.25 / 0.9 | Aim Accuracy: 0.75 / 0.95
- Reactiontime: 3.5 / 0.5
- Jumper: 0.75 | Weaponjumping: 0.75 | Grapple: 0.75
- Chat: ~263 Zeilen, 27 Typen

---

## 1. CORTANA (Halo)

### Persönlichkeit
Witty, sarkastisch, selbstbewusst. Taktisch brillant. Teasend aber loyal.
Mag es "crazy" zu spielen. Hohe Intelligenz, schnelle Reaktionen.

### Kampfstil: OFFENSIV-AGIL
Hohe Mobilität, präzises Aim, aktive Jagd. Kein Camping.

### Cvar-Werte (Skill 1 / Skill 4)
```
CHARACTERISTIC_GENDER             "female"
CHARACTERISTIC_ATTACK_SKILL       0.6 / 0.85
CHARACTERISTIC_AIM_SKILL          0.7 / 0.95
CHARACTERISTIC_AIM_ACCURACY       0.85 / 0.98
CHARACTERISTIC_VIEW_FACTOR        0.9 / 0.98
CHARACTERISTIC_VIEW_MAXCHANGE     150 / 220
CHARACTERISTIC_REACTIONTIME       1.5 / 0.3
CHARACTERISTIC_CROUCHER           0.05 / 0.02
CHARACTERISTIC_JUMPER             0.9 / 0.98
CHARACTERISTIC_WEAPONJUMPING      0.85 / 0.95
CHARACTERISTIC_GRAPPLE_USER       0.9 / 0.98
CHARACTERISTIC_AGGRESSION         0.6 / 0.7
CHARACTERISTIC_SELFPRESERVATION   0.7 / 0.8
CHARACTERISTIC_VENGEFULNESS       0.4 / 0.5
CHARACTERISTIC_CAMPER             0.1 / 0.05
CHARACTERISTIC_EASY_FRAGGER       0.6 / 0.8
CHARACTERISTIC_ALERTNESS          0.9 / 0.98
CHARACTERISTIC_CHAT_CPM           600 / 900
CHARACTERISTIC_CHAT_INSULT        0.4 / 0.5
CHARACTERISTIC_CHAT_MISC          0.6 / 0.7
CHARACTERISTIC_CHAT_KILL          0.6 / 0.7
CHARACTERISTIC_CHAT_DEATH         0.3 / 0.4
CHARACTERISTIC_CHAT_REPLY         0.7 / 0.8
```

### Waffen-Gewichtung
```
W_GAUNTLET        5    // Nein, nicht mein Stil
W_SHOTGUN         25   // Zu unpräzise
W_MACHINEGUN      50   // Okay als Backup
W_GRENADELAUNCHER 35   // Für Area-Denial
W_ROCKETLAUNCHER  70   // Gut gegen Gruppen
W_RAILGUN         380  // Präzision = Cortana
W_BFG10K          85   // Wenn's sein muss
W_LIGHTNING       95   // Energie-Waffe, Halo-Style
W_PLASMAGUN       90   // Energie-Waffe, Halo-Style
W_GRAPPLE         25   // Für Mobility
```

### Item-Prioritäten
```
W_QUAD            95   // Maximale Feuerkraft
W_HASTE           80   // Speed = Überleben
W_INVISIBILITY    75   // Taktischer Vorteil
W_FLIGHT          70   // Mobilität
W_TELEPORTER      65   // Positionierung
W_ENVIRO          50   // Nützlich
W_REGEN           45   // Nice to have
W_MEDKIT          40   // Nur wenn nötig
FLAG_WEIGHT       65   // CTF-relevant
```

### Chat-Sprüche (kurz, Ego-Shooter-Style)
```
// game_enter
"I calculated your odds. Not good."
"Let's make this interesting."
"Don't worry, I'll go easy on you. ...Just kidding."

// kill_insult
"Too slow."
"Predictable."
"My AI runs circles around your reflexes."

// kill_praise
"Not bad. For organic."
"Interesting move. Won't happen again though."

// death_insult
"Lucky shot. Recalculating..."
"I let you win that one."
"Temporary setback."

// death_praise
"Well played. Adjusting tactics."
"Noted. Adapting."

// level_end_victory
"Victory was statistically inevitable."
"GG. My algorithms are pleased."

// level_end_lose
"Recalibrating. Next round is mine."
"Data collected. You won't be lucky twice."

// random_misc
"I like crazy."
"When the game is over, the king and the pawn go in the same box."
"Bet you can't hit me."
```

### Avatar-Beschreibung
Holografische weibliche Figur. Blaue/purple leuchtende Linien auf transparentem/dunklem Hintergrund. Schlank, digital, futuristisch. Kurzes Haar oder Datenströme als Haare.
**Teamfarben:** Blue Team = blau/purple (Standard). Red Team = rot/orange Holo-Linien.

---

## 2. EDI (Mass Effect 3)

### Persönlichkeit
Analytisch, ruhig, deadpan-humorvoll. Lernt menschliches Verhalten.
Beschützend gegenüber Team. Stellt sachliche Fragen. "Blabbermouth"-Reputation.

### Kampfstil: BALANCED-TAKTISCH
Defensiv mit gezielten Gegenangriffen. Hohe Genauigkeit über Feuerrate.
Positioniert sich strategisch, hält Distanz.

### Cvar-Werte (Skill 1 / Skill 4)
```
CHARACTERISTIC_GENDER             "female"
CHARACTERISTIC_ATTACK_SKILL       0.5 / 0.8
CHARACTERISTIC_AIM_SKILL          0.65 / 0.92
CHARACTERISTIC_AIM_ACCURACY       0.9 / 0.98
CHARACTERISTIC_VIEW_FACTOR        0.85 / 0.95
CHARACTERISTIC_VIEW_MAXCHANGE     120 / 180
CHARACTERISTIC_REACTIONTIME       2.0 / 0.5
CHARACTERISTIC_CROUCHER           0.3 / 0.15
CHARACTERISTIC_JUMPER             0.6 / 0.8
CHARACTERISTIC_WEAPONJUMPING      0.5 / 0.7
CHARACTERISTIC_GRAPPLE_USER       0.7 / 0.85
CHARACTERISTIC_AGGRESSION         0.3 / 0.45
CHARACTERISTIC_SELFPRESERVATION   0.9 / 0.95
CHARACTERISTIC_VENGEFULNESS       0.1 / 0.15
CHARACTERISTIC_CAMPER             0.5 / 0.35
CHARACTERISTIC_EASY_FRAGGER       0.5 / 0.7
CHARACTERISTIC_ALERTNESS          0.85 / 0.95
CHARACTERISTIC_CHAT_CPM           500 / 700
CHARACTERISTIC_CHAT_INSULT        0.1 / 0.15
CHARACTERISTIC_CHAT_MISC          0.7 / 0.8
CHARACTERISTIC_CHAT_KILL          0.4 / 0.5
CHARACTERISTIC_CHAT_DEATH         0.3 / 0.35
CHARACTERISTIC_CHAT_REPLY         0.8 / 0.9
```

### Waffen-Gewichtung
```
W_GAUNTLET        5    // Ineffizient
W_SHOTGUN         30   // Defensive Option
W_MACHINEGUN      55   // Zuverlässig, kontrollierbar
W_GRENADELAUNCHER 40   // Area control
W_ROCKETLAUNCHER  65   // Balanced
W_RAILGUN         370  // Höchste Präzision
W_BFG10K          60   // Overkill, ineffizient
W_LIGHTNING       70   // Gute Reichweite
W_PLASMAGUN       65   // Solide Option
W_GRAPPLE         15   // Selten nötig
```

### Item-Prioritäten
```
W_QUAD            65   // Effizient aber riskant
W_HASTE           50   // Moderat nützlich
W_INVISIBILITY    55   // Taktisch wertvoll
W_FLIGHT          45   // Positionierung
W_TELEPORTER      50   // Strategisch
W_ENVIRO          60   // Schutz priorisiert
W_REGEN           70   // Selbsterhaltung hoch
W_MEDKIT          75   // Gesundheit = Priorität
FLAG_WEIGHT       75   // Team-orientiert
```

### Chat-Sprüche (kurz, analytisch, deadpan)
```
// game_enter
"Threat assessment in progress."
"Analyzing combat parameters."
"I've been told I talk too much. Noted."

// kill_insult
"Your tactical error was predictable."
"Inefficient positioning."
"I expected more resistance."

// kill_praise
"Adequate performance. Noted."
"Acceptable countermeasure."

// death_insult
"Suboptimal outcome. Analyzing cause."
"Tactical miscalculation on my part."
"Data point recorded."

// death_praise
"Effective strategy. Adding to database."
"Impressive. Updating threat models."

// level_end_victory
"Optimal outcome achieved."
"Mission parameters satisfied."

// level_end_lose
"Performance below acceptable thresholds. Adjusting."
"Insufficient data. Requesting rematch."

// random_misc
"I'm curious about human aggression. Still studying."
"Joker says I'm a blabbermouth. I disagree."
"Probability of your survival: declining."
```

### Avatar-Beschreibung
Humanoider Roboter-Körper. Silber-metallisch mit blauen Lichtakzenten an Gelenken und Augen. Elegante, schlanke Silhouette. Gesicht glatt, keine menschlichen Züge außer grober Form.
**Teamfarben:** Blue Team = silber/blau (Standard). Red Team = silber/rot-orange Akzente.

---

## 3. DOG (Half-Life 2)

### Persönlichkeit
Verspielt, loyal, energisch, beschützend. Wird extrem gefährlich wenn
Freunde bedroht sind. Trotz massiver Erscheinung freundlich und anhänglich.
Bellt, springt, spielt Fetch mit Gegnern.

### Kampfstil: OFFENSIV-BRUTAL
Nahkampf-orientiert, extrem hohe HP/Toleranz. Stürmt direkt rein.
Nutzt Masse und Stärke. Verfolgt Gegner wie ein Hund einen Ball.

### Cvar-Werte (Skill 1 / Skill 4)
```
CHARACTERISTIC_GENDER             "male"
CHARACTERISTIC_ATTACK_SKILL       0.5 / 0.75
CHARACTERISTIC_AIM_SKILL          0.4 / 0.7
CHARACTERISTIC_AIM_ACCURACY       0.55 / 0.75
CHARACTERISTIC_VIEW_FACTOR        0.7 / 0.85
CHARACTERISTIC_VIEW_MAXCHANGE     100 / 160
CHARACTERISTIC_REACTIONTIME       2.5 / 1.0
CHARACTERISTIC_CROUCHER           0.05 / 0.02
CHARACTERISTIC_JUMPER             0.8 / 0.9
CHARACTERISTIC_WEAPONJUMPING      0.7 / 0.85
CHARACTERISTIC_GRAPPLE_USER       0.6 / 0.75
CHARACTERISTIC_AGGRESSION         0.7 / 0.85
CHARACTERISTIC_SELFPRESERVATION   0.4 / 0.5
CHARACTERISTIC_VENGEFULNESS       0.8 / 0.9
CHARACTERISTIC_CAMPER             0.05 / 0.02
CHARACTERISTIC_EASY_FRAGGER       0.7 / 0.85
CHARACTERISTIC_ALERTNESS          0.7 / 0.85
CHARACTERISTIC_CHAT_CPM           400 / 600
CHARACTERISTIC_CHAT_INSULT        0.2 / 0.3
CHARACTERISTIC_CHAT_MISC          0.5 / 0.6
CHARACTERISTIC_CHAT_KILL          0.7 / 0.8
CHARACTERISTIC_CHAT_DEATH         0.4 / 0.5
CHARACTERISTIC_CHAT_REPLY         0.5 / 0.6
```

### Waffen-Gewichtung
```
W_GAUNTLET        80   // NAHKAMPF! Dog's Spezialität
W_SHOTGUN         70   // Nahbereich, verheerend
W_MACHINEGUN      35   // Zu passiv für Dog
W_GRENADELAUNCHER 55   // BOOM!
W_ROCKETLAUNCHER  85   // EXPLOSIONEN! Dog liebt das
W_RAILGUN         100  // Zu ruhig/präzise für Dog
W_BFG10K          90   // GROSSER BOOM!
W_LIGHTNING       40   // Zu technisch
W_PLASMAGUN       35   // Zu subtil
W_GRAPPLE         20   // Dog springt lieber
```

### Item-Prioritäten
```
W_QUAD            85   // MEHR SCHADEN!
W_HASTE           70   // SCHNELLER!
W_INVISIBILITY    30   // Dog versteckt sich NICHT
W_FLIGHT          50   // Springen reicht meistens
W_TELEPORTER      40   // Langweilig
W_ENVIRO          55   // Rüstung gut
W_REGEN           60   // Dog heilt schnell
W_MEDKIT          80   // Dog braucht viel HP
FLAG_WEIGHT       50   // Fetch! Flag apportieren!
```

### Chat-Sprüche (kurz, hundeartig, enthusiastisch)
```
// game_enter
"*bark* Play time!"
"Who wants to play?!"
"Woof! Let's go!"

// kill_insult
"Fetch! *pant*"
"Gotcha! *tail wag*"
"That was fun! Again!"

// kill_praise
"Good throw! *happy bark*"
"You're fast! Like ball!"

// death_insult
"*whine*... That hurt."
"Ouch! Mean!"
"*growl* Not fair!"

// death_praise
"Wow! Strong! *respectful sit*"
"You hit hard! *bark*"

// level_end_victory
"*happy bark bark bark!* We won!"
"Best game ever! *tail wag*"

// level_end_lose
"*whine*... Rematch? Please?"
"Next time! *determined growl*"

// random_misc
"*bark*"
"Ball? Where's the ball?"
"*sniff sniff* Enemy nearby!"
"Woof!"
"Protecting friends! *growl*"
```

### Avatar-Beschreibung
Großer mechanischer Hund/Gorilla-Hybrid (~3m). Grau-metallisch mit gelben/orangen leuchtenden Augen. Massiv, vierbeinig, sichtbare Hydraulik. Freundlicher Gesichtsausdruck trotz Größe. Rostige Akzente an Gelenken.
**Teamfarben:** Blue Team = grau/blau-blaue Augen. Red Team = grau/rot-rote Augen + rote Markierungen.

---

## Vergleichstabelle

| Eigenschaft | Cortana | EDI | Dog | Grunt (Ref) |
|---|---|---|---|---|
| **Stil** | Offensiv-Agil | Balanced-Taktisch | Offensiv-Brutal | Balanced |
| **Aggression** | 0.6-0.7 | 0.3-0.45 | 0.7-0.85 | 0.5 |
| **Selfpreservation** | 0.7-0.8 | 0.9-0.95 | 0.4-0.5 | 0.75 |
| **Vengefulness** | 0.4-0.5 | 0.1-0.15 | 0.8-0.9 | 0.5 |
| **Camper** | 0.05-0.1 | 0.35-0.5 | 0.02-0.05 | 0.75 |
| **Top-Waffe** | Lightning/Plasma | Railgun | Gauntlet/Rocket | Railgun |
| **Chat-Stil** | Sarkastisch-witzig | Analytisch-deadpan | Hundeartig-enthusiastisch | Marine-Slang |
| **Geschlecht** | Female | Female | Male | Male |
