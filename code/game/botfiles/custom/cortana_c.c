#include "game/botlib.h"
#include "game/ai_chat.h"

//========================================================
//========================================================
//Name:			Cortana
//Model:		cortana
//Gender:		female
//========================================================
//========================================================

bot_character_t botcharacter_cortana = {
	"Cortana",
	0, 0, 0, 0, 0,
	{
		{"CHARACTERISTIC_GENDER",				"female"},
		{"CHARACTERISTIC_ATTACK_SKILL",			"0.6", "0.85"},
		{"CHARACTERISTIC_AIM_SKILL",			"0.7", "0.95"},
		{"CHARACTERISTIC_AIM_ACCURACY",			"0.85", "0.98"},
		{"CHARACTERISTIC_VIEW_FACTOR",			"0.9", "0.98"},
		{"CHARACTERISTIC_VIEW_MAXCHANGE",		"150", "220"},
		{"CHARACTERISTIC_REACTIONTIME",			"1.5", "0.3"},
		{"CHARACTERISTIC_CROUCHER",				"0.05", "0.02"},
		{"CHARACTERISTIC_JUMPER",				"0.9", "0.98"},
		{"CHARACTERISTIC_WEAPONJUMPING",		"0.85", "0.95"},
		{"CHARACTERISTIC_GRAPPLE_USER",			"0.9", "0.98"},
		{"CHARACTERISTIC_AGGRESSION",			"0.6", "0.7"},
		{"CHARACTERISTIC_SELFPRESERVATION",		"0.7", "0.8"},
		{"CHARACTERISTIC_VENGEFULNESS",			"0.4", "0.5"},
		{"CHARACTERISTIC_CAMPER",				"0.1", "0.05"},
		{"CHARACTERISTIC_EASY_FRAGGER",			"0.6", "0.8"},
		{"CHARACTERISTIC_ALERTNESS",			"0.9", "0.98"},
		{"CHARACTERISTIC_CHAT_CPM",				"600", "900"},
		{"CHARACTERISTIC_CHAT_INSULT",			"0.4", "0.5"},
		{"CHARACTERISTIC_CHAT_MISC",			"0.6", "0.7"},
		{"CHARACTERISTIC_CHAT_KILL",			"0.6", "0.7"},
		{"CHARACTERISTIC_CHAT_DEATH",			"0.3", "0.4"},
		{"CHARACTERISTIC_CHAT_REPLY",			"0.7", "0.8"},
		{NULL, NULL}
	},
	{
		{"W_GAUNTLET",			"5"},
		{"W_SHOTGUN",			"25"},
		{"W_MACHINEGUN",		"50"},
		{"W_GRENADELAUNCHER",	"35"},
		{"W_ROCKETLAUNCHER",	"70"},
		{"W_RAILGUN",			"380"},
		{"W_BFG10K",			"85"},
		{"W_LIGHTNING",			"95"},
		{"W_PLASMAGUN",			"90"},
		{"W_GRAPPLE",			"25"},
		{NULL, NULL}
	},
	{
		{"W_QUAD",				"95"},
		{"W_HASTE",				"80"},
		{"W_INVISIBILITY",		"75"},
		{"W_FLIGHT",			"70"},
		{"W_TELEPORTER",		"65"},
		{"W_ENVIRO",			"50"},
		{"W_REGEN",				"45"},
		{"W_MEDKIT",			"40"},
		{"FLAG_WEIGHT",			"65"},
		{NULL, NULL}
	}
};
