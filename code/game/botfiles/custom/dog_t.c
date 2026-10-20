//===========================================================================
//
// Name:			dog_t.c
// Function:		chat lines for Dog
// Programmer:		Prometheus AI
// Last update:		Oct 20, 2026
// Tab Size:		3 (real tabs)
//===========================================================================

chat "dog"
{
	#include "teamplay.h"
	//
	type "game_enter"
	{
		"*bark* Play time!";
		"Who wants to play?!";
		"Woof! Let us go!";
		HELLO5;
	} //end type

	type "game_exit"
	{
		"*happy bark* Good game!";
		"Time for nap. *yawn*";
		GOODBYE5;
	} //end type

	type "level_start"
	{
		"*sniff sniff* New place!";
		"Exploring! *tail wag*";
		LEVEL_START0;
	} //end type

	type "level_end"
	{
		"*pant pant* That was fun!";
		LEVEL_END0;
	} //end type

	type "level_end_victory"
	{
		"*happy bark bark bark!* We won!";
		"Best game ever! *tail wag*";
		LEVEL_END_VICTORY3;
	} //end type

	type "level_end_lose"
	{
		"*whine*... Rematch? Please?";
		"Next time! *determined growl*";
		LEVEL_END_LOSE1;
	} //end type

	//================================================================
	//================================================================

	type "death_telefrag"
	{
		DEATH_TELEFRAGGED0;
		"*surprised bark* Where did you come from?!";
	} //end type

	type "death_lava"
	{
		"*yelp* Hot hot hot!";
		DEATH_SUICIDE1;
	} //end type

	type "death_slime"
	{
		"*cough* Yucky stuff!";
	} //end type

	type "death_drown"
	{
		"*blub blub* Cannot breathe!";
		DEATH_DROWN1;
	} //end type

	type "death_suicide"
	{
		"*whine* Oops. My bad.";
		"Clumsy paws.";
		DEATH_SUICIDE1;
	} //end type

	type "death_gauntlet"
	{
		"*growl* Close fight, ", 0, "!";
		DEATH_GAUNTLET0;
	} //end type

	type "death_rail"
	{
		"*yelp* That hurt, ", 0, "!";
		DEATH_RAIL1;
	} //end type

	type "death_bfg"
	{
		"*big yelp* Too bright, ", 0, "!";
		DEATH_BFG0;
	} //end type

	type "death_insult"
	{
		"*whine*... That hurt.";
		"Ouch! Mean, ", 0, "!";
		"*growl* Not fair!";
		DEATH_INSULT4;
	} //end type

	type "death_praise"
	{
		"Wow! Strong, ", 0, "! *respectful sit*";
		"You hit hard! *bark*";
	} //end type

	//======================================================
	//======================================================

	type "hit_talking"
	{
		"*yelp* Hey! I was talking, ", 0, "!";
		"Rude! *growl*";
	} //end type

	type "hit_nodeath"
	{
		"*shake* Still standing, ", 0, "!";
		"That tickled!";
	} //end type

	type "hit_nokill"
	{
		"*bark* Got you, ", 0, "!";
		"Chase continues!";
	} //end type

	type "enemy_suicide"
	{
		"*tilt head* Why did you do that, ", 0, "?";
	} //end type

	//================================================================
	//================================================================

	type "kill_rail"
	{
		"*happy bark* Boom!";
		KILL_RAIL2;
	} //end type

	type "kill_gauntlet"
	{
		"*excited bark* Tag! You are it!";
	} //end type

	type "kill_telefrag"
	{
		"*confused bark* Where did they go?";
	} //end type

	type "kill_insult"
	{
		"Fetch! *pant*";
		"Gotcha! *tail wag*";
		"That was fun, ", 0, "! Again!";
	} //end type

	type "kill_praise"
	{
		"Good throw, ", 0, "! *happy bark*";
		"You are fast! Like ball!";
	} //end type

	//======================================================
	//======================================================

	type "random_misc"
	{
		"*bark*";
		"Ball? Where is the ball?";
		"*sniff sniff* Enemy nearby!";
		"Woof!";
		"Protecting friends! *growl*";
		MISC4;
	} //end type

	type "random_insult"
	{
		"*growl* You smell funny.";
		"Not as fast as me!";
	} //end type
} //end chat
