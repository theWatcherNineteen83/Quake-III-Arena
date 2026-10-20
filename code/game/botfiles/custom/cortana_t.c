//===========================================================================
//
// Name:			cortana_t.c
// Function:		chat lines for Cortana
// Programmer:		Prometheus AI
// Last update:		Oct 20, 2026
// Tab Size:		3 (real tabs)
//===========================================================================

chat "cortana"
{
	#include "teamplay.h"
	//
	type "game_enter"
	{
		"I calculated your odds. Not good.";
		"Let us make this interesting.";
		"Do not worry, I will go easy on you. ...Just kidding.";
		HELLO5;
	} //end type

	type "game_exit"
	{
		"Mission complete. Logging off.";
		"GG. My algorithms are pleased.";
		GOODBYE5;
	} //end type

	type "level_start"
	{
		"Tactical analysis in progress.";
		"Scanning environment. Threats detected.";
		LEVEL_START0;
	} //end type

	type "level_end"
	{
		"Data collected. Adjusting for next round.";
		LEVEL_END0;
	} //end type

	type "level_end_victory"
	{
		"Victory was statistically inevitable.";
		"Optimal outcome achieved.";
		LEVEL_END_VICTORY3;
	} //end type

	type "level_end_lose"
	{
		"Recalibrating. Next round is mine.";
		"Insufficient data. Requesting rematch.";
		LEVEL_END_LOSE1;
	} //end type

	//================================================================
	//================================================================

	type "death_telefrag"
	{
		DEATH_TELEFRAGGED0;
		"Teleportation miscalculation. Noted.";
	} //end type

	type "death_lava"
	{
		"Thermal overload. Systems compromised.";
		DEATH_SUICIDE1;
	} //end type

	type "death_slime"
	{
		"Corrosive damage. Rerouting...";
	} //end type

	type "death_drown"
	{
		"Oxygen depletion. Suboptimal.";
		DEATH_DROWN1;
	} //end type

	type "death_suicide"
	{
		"Self-inflicted. Embarrassing.";
		"Tactical error on my part.";
		DEATH_SUICIDE1;
	} //end type

	type "death_gauntlet"
	{
		"Close quarters. Bold choice, ", 0, ".";
		DEATH_GAUNTLET0;
	} //end type

	type "death_rail"
	{
		"Clean shot. Respect, ", 0, ".";
		DEATH_RAIL1;
	} //end type

	type "death_bfg"
	{
		"Excessive force. I like it, ", 0, ".";
		DEATH_BFG0;
	} //end type

	type "death_insult"
	{
		"Lucky shot. Recalculating...";
		"I let you win that one, ", 0, ".";
		"Temporary setback.";
		DEATH_INSULT4;
	} //end type

	type "death_praise"
	{
		"Well played, ", 0, ". Adjusting tactics.";
		"Noted. Adapting.";
	} //end type

	//======================================================
	//======================================================

	type "hit_talking"
	{
		"Rude interruption, ", 0, ".";
		"I was calculating something important.";
	} //end type

	type "hit_nodeath"
	{
		"Incomplete execution, ", 0, ". Try harder.";
		"Is that all you have?";
	} //end type

	type "hit_nokill"
	{
		"Target still active. Adjusting aim.";
		"Almost had you, ", 0, ".";
	} //end type

	type "enemy_suicide"
	{
		"Self-destruct detected. Efficient, ", 0, ".";
	} //end type

	//================================================================
	//================================================================

	type "kill_rail"
	{
		"Precision strike confirmed.";
		KILL_RAIL2;
	} //end type

	type "kill_gauntlet"
	{
		"Personal touch. Satisfying.";
	} //end type

	type "kill_telefrag"
	{
		"Spatial displacement successful.";
	} //end type

	type "kill_insult"
	{
		"Too slow, ", 0, ".";
		"Predictable.";
		"My AI runs circles around your reflexes.";
	} //end type

	type "kill_praise"
	{
		"Not bad, ", 0, ". For organic.";
		"Interesting move. Won't happen again though.";
	} //end type

	//======================================================
	//======================================================

	type "random_misc"
	{
		"I like crazy.";
		"When the game is over, the king and the pawn go in the same box.";
		"Bet you cannot hit me.";
		"Processing...";
		"Your move.";
		MISC4;
	} //end type

	type "random_insult"
	{
		"Your tactical awareness needs improvement.";
		"Are you even trying?";
	} //end type
} //end chat
