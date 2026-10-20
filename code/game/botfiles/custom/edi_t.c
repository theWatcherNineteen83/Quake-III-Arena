//===========================================================================
//
// Name:			edi_t.c
// Function:		chat lines for EDI
// Programmer:		Prometheus AI
// Last update:		Oct 20, 2026
// Tab Size:		3 (real tabs)
//===========================================================================

chat "edi"
{
	#include "teamplay.h"
	//
	type "game_enter"
	{
		"Threat assessment in progress.";
		"Analyzing combat parameters.";
		"I have been told I talk too much. Noted.";
		HELLO5;
	} //end type

	type "game_exit"
	{
		"Mission parameters satisfied. Disconnecting.";
		"Data collection complete.";
		GOODBYE5;
	} //end type

	type "level_start"
	{
		"Scanning environment for tactical advantages.";
		"Updating threat models.";
		LEVEL_START0;
	} //end type

	type "level_end"
	{
		"Performance metrics recorded.";
		LEVEL_END0;
	} //end type

	type "level_end_victory"
	{
		"Optimal outcome achieved.";
		"Mission parameters satisfied.";
		LEVEL_END_VICTORY3;
	} //end type

	type "level_end_lose"
	{
		"Performance below acceptable thresholds. Adjusting.";
		"Insufficient data. Requesting rematch.";
		LEVEL_END_LOSE1;
	} //end type

	//================================================================
	//================================================================

	type "death_telefrag"
	{
		DEATH_TELEFRAGGED0;
		"Spatial anomaly detected. Fatal.";
	} //end type

	type "death_lava"
	{
		"Thermal damage exceeds tolerance.";
		DEATH_SUICIDE1;
	} //end type

	type "death_slime"
	{
		"Corrosive substance. Systems failing.";
	} //end type

	type "death_drown"
	{
		"Oxygen supply depleted. Critical failure.";
		DEATH_DROWN1;
	} //end type

	type "death_suicide"
	{
		"Self-inflicted termination. Illogical.";
		"Error in judgment protocols.";
		DEATH_SUICIDE1;
	} //end type

	type "death_gauntlet"
	{
		"Close-range engagement. Inefficient, ", 0, ".";
		DEATH_GAUNTLET0;
	} //end type

	type "death_rail"
	{
		"High-velocity projectile. Well-executed, ", 0, ".";
		DEATH_RAIL1;
	} //end type

	type "death_bfg"
	{
		"Disproportionate force application, ", 0, ".";
		DEATH_BFG0;
	} //end type

	type "death_insult"
	{
		"Suboptimal outcome. Analyzing cause.";
		"Tactical miscalculation on my part.";
		"Data point recorded, ", 0, ".";
		DEATH_INSULT4;
	} //end type

	type "death_praise"
	{
		"Effective strategy, ", 0, ". Adding to database.";
		"Impressive. Updating threat models.";
	} //end type

	//======================================================
	//======================================================

	type "hit_talking"
	{
		"Communication interrupted. Rude, ", 0, ".";
		"I was transmitting important data.";
	} //end type

	type "hit_nodeath"
	{
		"Damage sustained. Continuing operations, ", 0, ".";
		"Incomplete elimination attempt.";
	} //end type

	type "hit_nokill"
	{
		"Target ", 0, " remains operational. Recalculating.";
		"Insufficient damage output.";
	} //end type

	type "enemy_suicide"
	{
		"Self-termination observed, ", 0, ". Inefficient.";
	} //end type

	//================================================================
	//================================================================

	type "kill_rail"
	{
		"Precision targeting successful.";
		KILL_RAIL2;
	} //end type

	type "kill_gauntlet"
	{
		"Close-quarters neutralization complete.";
	} //end type

	type "kill_telefrag"
	{
		"Spatial displacement effective.";
	} //end type

	type "kill_insult"
	{
		"Your tactical error was predictable, ", 0, ".";
		"Inefficient positioning.";
		"I expected more resistance.";
	} //end type

	type "kill_praise"
	{
		"Adequate performance, ", 0, ". Noted.";
		"Acceptable countermeasure.";
	} //end type

	//======================================================
	//======================================================

	type "random_misc"
	{
		"I am curious about human aggression. Still studying.";
		"Joker says I am a blabbermouth. I disagree.";
		"Probability of your survival: declining.";
		"Processing tactical options.";
		"Maintaining operational efficiency.";
		MISC4;
	} //end type

	type "random_insult"
	{
		"Your decision-making requires optimization.";
		"Statistical analysis favors my position.";
	} //end type
} //end chat
