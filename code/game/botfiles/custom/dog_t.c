chat "dog"
{
	#include "teamplay.h"
	type "game_enter"
	{
		"Dog online.";
		"Ready to fight.";
	}
	type "game_exit"
	{
		"Dog out.";
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
