chat "cortana"
{
	#include "teamplay.h"
	type "game_enter"
	{
		"Cortana online.";
		"Ready to fight.";
	}
	type "game_exit"
	{
		"Cortana out.";
		"GG.";
	}
	type "kill"
	{
		"Target eliminated.";
		"Nice shot.";
	}
	type "death"
	{
		"Respawning...";
		"Not bad.";
	}
	type "misc"
	{
		"Moving.";
		"Cover me.";
	}
}
