#include "game/botlib.h"
#include "game/ai_chat.h"

//========================================================
//========================================================
//Name:			Dog
//Model:		dog
//Gender:		male
//========================================================
//========================================================

bot_character_t botcharacter_dog = {
	"Dog",
	0, 0, 0, 0, 0,
	{
		{"CHARACTERISTIC_GENDER",				"male"},
		{"CHARACTERISTIC_ATTACK_SKILL",			"0.5", "0.75"},
		{"CHARACTERISTIC_AIM_SKILL",			"0.4", "0.7"},
		{"CHARACTERISTIC_AIM_ACCURACY",			"0.55", "0.75"},
		{"CHARACTERISTIC_VIEW_FACTOR",			"0.7", "0.85"},
		{"CHARACTERISTIC_VIEW_MAXCHANGE",		"100", "160"},
		{"CHARACTERISTIC_REACTIONTIME",			"2.5", "1.0"},
		{"CHARACTERISTIC_CROUCHER",				"0.05", "0.02"},
		{"CHARACTERISTIC_JUMPER",				"0.8", "0.9"},
		{"CHARACTERISTIC_WEAPONJUMPING",		"0.7", "0.85"},
		{"CHARACTERISTIC_GRAPPLE_USER",			"0.6", "0.75"},
		{"CHARACTERISTIC_AGGRESSION",			"0.7", "0.85"},
		{"CHARACTERISTIC_SELFPRESERVATION",		"0.4", "0.5"},
		{"CHARACTERISTIC_VENGEFULNESS",			"0.8", "0.9"},
		{"CHARACTERISTIC_CAMPER",				"0.05", "0.02"},
		{"CHARACTERISTIC_EASY_FRAGGER",			"0.7", "0.85"},
		{"CHARACTERISTIC_ALERTNESS",			"0.7", "0.85"},
		{"CHARACTERISTIC_CHAT_CPM",				"400", "600"},
		{"CHARACTERISTIC_CHAT_INSULT",			"0.2", "0.3"},
		{"CHARACTERISTIC_CHAT_MISC",			"0.5", "0.6"},
		{"CHARACTERISTIC_CHAT_KILL",			"0.7", "0.8"},
		{"CHARACTERISTIC_CHAT_DEATH",			"0.4", "0.5"},
		{"CHARACTERISTIC_CHAT_REPLY",			"0.5", "0.6"},
		{NULL, NULL}
	},
	{
		{"W_GAUNTLET",			"80"},
		{"W_SHOTGUN",			"70"},
		{"W_MACHINEGUN",		"35"},
		{"W_GRENADELAUNCHER",	"55"},
		{"W_ROCKETLAUNCHER",	"85"},
		{"W_RAILGUN",			"100"},
		{"W_BFG10K",			"90"},
		{"W_LIGHTNING",			"40"},
		{"W_PLASMAGUN",			"35"},
		{"W_GRAPPLE",			"20"},
		{NULL, NULL}
	},
	{
		{"W_QUAD",				"85"},
		{"W_HASTE",				"70"},
		{"W_INVISIBILITY",		"30"},
		{"W_FLIGHT",			"50"},
		{"W_TELEPORTER",		"40"},
		{"W_ENVIRO",			"55"},
		{"W_REGEN",				"60"},
		{"W_MEDKIT",			"80"},
		{"FLAG_WEIGHT",			"50"},
		{NULL, NULL}
	}
};
