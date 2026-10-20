#include "game/botlib.h"
#include "game/ai_chat.h"

//========================================================
//========================================================
//Name:			EDI
//Model:		edi
//Gender:		female
//========================================================
//========================================================

bot_character_t botcharacter_edi = {
	"EDI",
	0, 0, 0, 0, 0,
	{
		{"CHARACTERISTIC_GENDER",				"female"},
		{"CHARACTERISTIC_ATTACK_SKILL",			"0.5", "0.8"},
		{"CHARACTERISTIC_AIM_SKILL",			"0.65", "0.92"},
		{"CHARACTERISTIC_AIM_ACCURACY",			"0.9", "0.98"},
		{"CHARACTERISTIC_VIEW_FACTOR",			"0.85", "0.95"},
		{"CHARACTERISTIC_VIEW_MAXCHANGE",		"120", "180"},
		{"CHARACTERISTIC_REACTIONTIME",			"2.0", "0.5"},
		{"CHARACTERISTIC_CROUCHER",				"0.3", "0.15"},
		{"CHARACTERISTIC_JUMPER",				"0.6", "0.8"},
		{"CHARACTERISTIC_WEAPONJUMPING",		"0.5", "0.7"},
		{"CHARACTERISTIC_GRAPPLE_USER",			"0.7", "0.85"},
		{"CHARACTERISTIC_AGGRESSION",			"0.3", "0.45"},
		{"CHARACTERISTIC_SELFPRESERVATION",		"0.9", "0.95"},
		{"CHARACTERISTIC_VENGEFULNESS",			"0.1", "0.15"},
		{"CHARACTERISTIC_CAMPER",				"0.5", "0.35"},
		{"CHARACTERISTIC_EASY_FRAGGER",			"0.5", "0.7"},
		{"CHARACTERISTIC_ALERTNESS",			"0.85", "0.95"},
		{"CHARACTERISTIC_CHAT_CPM",				"500", "700"},
		{"CHARACTERISTIC_CHAT_INSULT",			"0.1", "0.15"},
		{"CHARACTERISTIC_CHAT_MISC",			"0.7", "0.8"},
		{"CHARACTERISTIC_CHAT_KILL",			"0.4", "0.5"},
		{"CHARACTERISTIC_CHAT_DEATH",			"0.3", "0.35"},
		{"CHARACTERISTIC_CHAT_REPLY",			"0.8", "0.9"},
		{NULL, NULL}
	},
	{
		{"W_GAUNTLET",			"5"},
		{"W_SHOTGUN",			"30"},
		{"W_MACHINEGUN",		"55"},
		{"W_GRENADELAUNCHER",	"40"},
		{"W_ROCKETLAUNCHER",	"65"},
		{"W_RAILGUN",			"370"},
		{"W_BFG10K",			"60"},
		{"W_LIGHTNING",			"70"},
		{"W_PLASMAGUN",			"65"},
		{"W_GRAPPLE",			"15"},
		{NULL, NULL}
	},
	{
		{"W_QUAD",				"65"},
		{"W_HASTE",				"50"},
		{"W_INVISIBILITY",		"55"},
		{"W_FLIGHT",			"45"},
		{"W_TELEPORTER",		"50"},
		{"W_ENVIRO",			"60"},
		{"W_REGEN",				"70"},
		{"W_MEDKIT",			"75"},
		{"FLAG_WEIGHT",			"75"},
		{NULL, NULL}
	}
};
