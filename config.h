#ifndef DC_FIDELITY_CONFIG

#include "data/scripts/dc_d20/main.c"

#define DC_FIDELITY_CONFIG 1

// Name of library. Used mainly as a base for variable IDs. Must
// be unique vs all other libraries. Try to keep it short.
#define DC_FIDELITY_BASE_ID	 "dcfid"

// Logging. Controls what processes get logged for debugging. 
// Uses a bit masked macro, so add desired options to the
// control flag. Note some "fail" conditions may be intentional, 
// such as calling for a sound type a category does not have
// and falling back to the global category.

// Logging options.
#define DC_FIDELITY_LOG_LOAD				1	// Loading and setup of sound files.
#define DC_FIDELITY_LOG_FAIL_CATEGORY		2	// Log when a specified category is not found. 
#define DC_FIDELITY_LOG_FAIL_TYPE			4	// Log when a specified type is not found in category.
#define DC_FIDELITY_LOG_FAIL_INDEX			8	// Log when a specified type does not have any indexes.
#define DC_FIDELITY_LOG_FAIL_SAMPLE			16	// Log when a specified index does not contain a valid sample ID.
#define DC_FIDELITY_LOG_PLAY				32	// Log when sound plays.
#define DC_FIDELITY_LOG_UNLOAD				64	// Log unloading of sounds.

// Logging control flag.
#define DC_FIDELITY_LOG						DC_FIDELITY_LOG_LOAD + DC_FIDELITY_LOG_FAIL_CATEGORY + DC_FIDELITY_LOG_FAIL_TYPE + DC_FIDELITY_LOG_FAIL_INDEX + DC_FIDELITY_LOG_FAIL_SAMPLE + DC_FIDELITY_LOG_PLAY + DC_FIDELITY_LOG_UNLOAD

// Sound Categories
//
// Normally sound categories are given the name of a model. 
// When an entity is instructed to play
// a type of sound (see below), its base model is 
// used to select the category. This is not a 
// requirement though, it is just the default
// behavior. You can load sounds with whatever you
// feel like as a category name and override the 
// sound system's default automatic category selection
// when playing a sound type.
//
// This is a list of predefined custom categories. 
// One example might be global whiff or hit sounds. 
// You aren't required to use this list when you 
// create custom categories, but it's a good idea 
// just to keep yourself organized. Add as many
// categories as you wish, just make sure they are 
// unique to each other and don't match any of your 
// model names.
//
// Note: DC_FIDELITY_CATEGORY_GLOBAL is a special category 
// used as a default fallback (you can switch this behavior 
// off). If a sound type does not exist for the requested 
// category, the sound system will look for that type in 
// the global category instead. If the type is not found 
// in global category either, no sound is played.
#define DC_FIDELITY_CATEGORY_GLOBAL			0
#define DC_FIDELITY_CATEGORY_MALE			1
#define DC_FIDELITY_CATEGORY_FEMALE			2

// Sound Types.
//
// Sound types are the specific types of sounds you 
// assign to each category (see above), and then instruct 
// the sound system to play. For instance, a model's
// voice effect when making a heavy attack. Each type 
// can be loaded mutiple times with different sound 
// files, in which case the sound will be picked 
// randomly each time the play function is executed.
//
// As with categories, feel free to create and use
// sound types at your discretion. 

// Sound effects.
#define DC_FIDELITY_TYPE_SOUND_SPAWN				0	// Spawn sound.
#define DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY			1	// "Air" sound, heavy attacks.
#define DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY_BLADE	2	// "Air" sound, heavy attacks (blade).
#define DC_FIDELITY_TYPE_SOUND_ATTACK_LIGHT			3	// "Air" sound, light attacks.
#define DC_FIDELITY_TYPE_SOUND_ATTACK_LIGHT_BLADE	4	// "Air" sound, light attacks (blade).
#define DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM		5	// "Air" sound, medium attacks.
#define DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM_BLADE	6	// "Air" sound, medium attacks (blade).
#define DC_FIDELITY_TYPE_SOUND_IMPACT_HEAVY			7	// Attack hit sound, heavy attacks.
#define DC_FIDELITY_TYPE_SOUND_IMPACT_HEAVY_BLADE	8	// Attack hit sound, heavy attacks (blade).
#define DC_FIDELITY_TYPE_SOUND_IMPACT_LIGHT			9	// Attack hit sound, light attacks.
#define DC_FIDELITY_TYPE_SOUND_IMPACT_LIGHT_BLADE	10	// Attack hit sound, light attacks (blade).
#define DC_FIDELITY_TYPE_SOUND_IMPACT_MEDIUM		11	// Attack hit sound, medium attacks.
#define DC_FIDELITY_TYPE_SOUND_IMPACT_MEDIUM_BLADE	12	// Attack hit sound, medium attacks (blade).

// Voices.
#define DC_FIDELITY_TYPE_VOICE_ATTACK_COMMAND		12	// Attack saying. - "Let's get them!", or "Ready your weapon! Let's go!"
#define DC_FIDELITY_TYPE_VOICE_ATTACK_FAIL			14	// Attack did nothing.- "This guy is invincible!", "Oh crap, not a scrath!", ...
#define DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY	15	// Yalp while attacking. - Ha! ya! ...
#define DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT	16	// Yalp while attacking. - Ha! ya! ...
#define DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM	17	// Yalp while attacking. - Ha! ya! ...
#define DC_FIDELITY_TYPE_VOICE_ATTACK_TAUNT			18	// Successful attack (KO for players, knockdown for AI). - "That was too easy!", "Fall before me!", ...
#define DC_FIDELITY_TYPE_VOICE_BAD_IDEA				19	// Skeptical, negative saying. - "That's a stupid plan.", "Lay off the crack pipe.", ...
#define DC_FIDELITY_TYPE_VOICE_BATTLE_CRY			20	// In battle rally. - "I'll kick your ass!", "No one shall default us!", ...
#define DC_FIDELITY_TYPE_VOICE_BORED				21	// Bored saying. - "For fighters we seem to be doing little fighting", "This is certainly one way of not getting anywhere.", ...
#define DC_FIDELITY_TYPE_VOICE_CAN_DO				22	// Comply to a task request. - "Sure thing, I'll take care of it.", "I got this.", ...
#define DC_FIDELITY_TYPE_VOICE_CANT_DO				23	// Can't do a task. - "Sorry, no can do.", "No I can do that.", ...
#define DC_FIDELITY_TYPE_VOICE_CHEER				24	// Exclamation of joy saying. - "Hurrah!", "Yes! All right!.", ...
#define DC_FIDELITY_TYPE_VOICE_CUSS					25	// Pissed off. - "Damn it!", "Son of a bitch!", ...
#define DC_FIDELITY_TYPE_VOICE_ENCUMBERED			26	// Load is too heavy. - "I'm not a pack mule!", "I have to lighten this load!", ...
#define DC_FIDELITY_TYPE_VOICE_ENEMIES				27	// Spotted opponents. - "There's the enemy.", "That's them up a ahead.", ...
#define DC_FIDELITY_TYPE_VOICE_FLEE					28	// Run! - "We're outmatched, let's beat it!", "Every man for himself!", ...
#define DC_FIDELITY_TYPE_VOICE_FOLLOW_ME			29	// Request to follow. - "Come with me please.", "Stay close behind me.", ...		
#define DC_FIDELITY_TYPE_VOICE_GOOD_BYE				30	// Farewell greeting. - "Until we meet again.", "See you later.", ...
#define DC_FIDELITY_TYPE_VOICE_GOOD_IDEA			31	// Agree with plan. - "That's a fine idea.", "Good thinking!", ...
#define DC_FIDELITY_TYPE_VOICE_GROUP				32	// Form up. - "Close ranks quickly.", "Everyone to me!", ...
#define DC_FIDELITY_TYPE_VOICE_GUARD_ME				33	// Request protection. - "Watch over me.", "You take first watch.", ...
#define DC_FIDELITY_TYPE_VOICE_HEAL_ME				34	// Request healing aid. - "I need medical help!", "Patch me up!", ...	
#define DC_FIDELITY_TYPE_VOICE_HELLO				35	// Conversation greeting. - "Hello there.", "Well met friend.", ...
#define DC_FIDELITY_TYPE_VOICE_HELP					36	// Request assistence. - "I need some help!", "Lend me your skill!", ...
#define DC_FIDELITY_TYPE_VOICE_HIDE					37	// Request stealth - "Be quick and quiet.", "Keep it down everyone.", ...
#define DC_FIDELITY_TYPE_VOICE_HOLD					38	// Request to hold ground. - "Hold your position.", "Wait here a moment.", ...
#define DC_FIDELITY_TYPE_VOICE_KO					39	// Defeated by standard means.
#define DC_FIDELITY_TYPE_VOICE_KO_PIT				40	// Defeated by falling into pit, thrown great distance, etc. - "Ahhhhhhhhhhhhhhhhhhh!", "Noooooooooooooooo!", ...
#define DC_FIDELITY_TYPE_VOICE_LAUGH				41	// Amused laughing.
#define DC_FIDELITY_TYPE_VOICE_LOOK_HERE			42	// Found something. - "Everyone, look at this.", "I see something in the bush.", ...
#define DC_FIDELITY_TYPE_VOICE_MOVE_OVER			43	// Move out of the way. - "Let me pass.", "Please step aside.", ...
#define DC_FIDELITY_TYPE_VOICE_NEAR_KO				44	// Damaged at low HP. - "I'm in big trouble here!", "I can't take another hit like that!", ...
#define DC_FIDELITY_TYPE_VOICE_NO					45	// Negative response. - "Of course not.", "No.", ... 
#define DC_FIDELITY_TYPE_VOICE_PAIN					46	// Taking damage. - "Oof!", "Ow!", ...
#define DC_FIDELITY_TYPE_VOICE_PAIN_FALL			47	// Taking damage and knocked down. - "Oof!", "Ow!", ...
#define DC_FIDELITY_TYPE_VOICE_PAIN_BURN			48	// Taking damage from fire or heat. - "Yarrrrrgh!", "I'm on fire!", ...
#define DC_FIDELITY_TYPE_VOICE_PAIN_SHOCK			49	// Taking damage from electricity. - "Bzzzt", "Ooooh, sparky!", ...
#define DC_FIDELITY_TYPE_VOICE_PICK_LOCK			50	// Request to open a lock. - "Anyone got a key?", "Can you get this open?"
#define DC_FIDELITY_TYPE_VOICE_POISONED				51	// Noticed poision - "I don't feel so good...", "I've been envenomed.", ...
#define DC_FIDELITY_TYPE_VOICE_REST					52	// Request a rest. - "Time for a break.", "Let's rest here a moment.", ...
#define DC_FIDELITY_TYPE_VOICE_SEARCH				53	// Request an area search. - "Let's look around a bit.", "Don't leave a stone un-turned.", ...
#define DC_FIDELITY_TYPE_VOICE_SELECTION_GREET		54	// Highlighted at selection screen. - "Hey, pick me!", "You can't pass up on this!", ...
#define DC_FIDELITY_TYPE_VOICE_SELECTION_PICK		55	// Choosen by player at select screen. - "Nice choice!", "OK, let's do it!", ...
#define DC_FIDELITY_TYPE_VOICE_SELECTION_WAIT		56	// Waiting after highlighted at selection screen. - "Make up your mind man!", "What are you waiting for?", ...
#define DC_FIDELITY_TYPE_VOICE_SELECTED				57	// Reactive greeting. - "Is there something you need?", "Yes? Can I help you?", ...
#define DC_FIDELITY_TYPE_VOICE_SPELL_FAILED			58	// Magic or special attack fails, can't be used. - "I don't have the energy for that.", "My magic has failed me!", ...
#define DC_FIDELITY_TYPE_VOICE_STOP					59	// Stop request. - "Stop right there.", "Hold up a second!", ...
#define DC_FIDELITY_TYPE_VOICE_TALK_TO_ME			60	// Request to talk. - "We need to chat.", "Please have a word with me.", ...
#define DC_FIDELITY_TYPE_VOICE_TASK_COMPLETE		61	// Task finished. - "All done.", "Finished. What's next?", ...
#define DC_FIDELITY_TYPE_VOICE_TAUNT				62	// Taunt opponent. - "Bring it on chump!", "You don't have a prayer.", ...
#define DC_FIDELITY_TYPE_VOICE_THANKS				63	// Express gratitude. - "I apprciate that.", "Thank you so much.", ...
#define DC_FIDELITY_TYPE_VOICE_THREATEN				64	// Warning. - "You're messing with the wrong guy.", "Keep it up and I'll knock you into last week, so you can wait until now for me to kick your ass again!"
#define DC_FIDELITY_TYPE_VOICE_YES					65	// Agree. - "Sure.", "Yes.", ...

// Options.
#define DC_FIDELITY_INDEX_RANDOM	-1		// Seek a random sound index from sound type.
#define DC_FIDELITY_SAMPLE_NONE		-1		// No sample, or invalid sample.		

// Default values.
#define DC_FIDELITY_DEFAULT_INSTANCE						0
#define DC_FIDELITY_DEFAULT_ENT								getlocalvar("self")
#define DC_FIDELITY_DEFAULT_CATEGORY_LIST					NULL()
#define DC_FIDELITY_DEFAULT_GLOBAL_FALLBACK					1		// Try global category when specific category doesn't have sound type.
#define DC_FIDELITY_DEFAULT_SOUND_CHANCE					1.0
#define DC_FIDELITY_DEFAULT_SOUND_LOCATION_BALANCE			1		// Adjust volume based on a given X position in relation to screen.
#define DC_FIDELITY_DEFAULT_SOUND_LOCATION_FADE				0		// Adjust volume based on a given Z position in relation to screen.
#define DC_FIDELITY_DEFAULT_SOUND_LOOP						0
#define DC_FIDELITY_DEFAULT_SOUND_PRIORITY					1
#define DC_FIDELITY_DEFAULT_SOUND_SPEED						100
#define DC_FIDELITY_DEFAULT_SOUND_VOLUME_LEFT				200
#define DC_FIDELITY_DEFAULT_SOUND_VOLUME_RIGHT				200

// Variable keys.
#define DC_FIDELITY_VAR_KEY_INSTANCE						DC_FIDELITY_BASE_ID + 0
#define DC_FIDELITY_VAR_KEY_ENT								DC_FIDELITY_BASE_ID + 1		
#define DC_FIDELITY_VAR_KEY_GLOBAL_FALLBACK					DC_FIDELITY_BASE_ID + 2	
#define DC_FIDELITY_VAR_KEY_SOUND_CATEGORY					DC_FIDELITY_BASE_ID + 3		// Global var used to store list of categories -> types ->indexes.
#define DC_FIDELITY_VAR_KEY_SOUND_CHANCE					DC_FIDELITY_BASE_ID + 4
#define DC_FIDELITY_VAR_KEY_SOUND_ELEMENT					DC_FIDELITY_BASE_ID + 5
#define DC_FIDELITY_VAR_KEY_SOUND_ENTITY					DC_FIDELITY_BASE_ID + 6
#define DC_FIDELITY_VAR_KEY_SOUND_LOCATION_BALANCE			DC_FIDELITY_BASE_ID + 7
#define DC_FIDELITY_VAR_KEY_SOUND_LOCATION_FADE				DC_FIDELITY_BASE_ID + 8
#define DC_FIDELITY_VAR_KEY_SOUND_LOOP						DC_FIDELITY_BASE_ID + 9
#define DC_FIDELITY_VAR_KEY_SOUND_PRIORITY					DC_FIDELITY_BASE_ID + 10
#define DC_FIDELITY_VAR_KEY_SOUND_SPEED						DC_FIDELITY_BASE_ID + 11
#define DC_FIDELITY_VAR_KEY_SOUND_VOLUME_MAIN_LEFT			DC_FIDELITY_BASE_ID + 12	// Left channel volume before any adjustments are made.
#define DC_FIDELITY_VAR_KEY_SOUND_VOLUME_MAIN_RIGHT			DC_FIDELITY_BASE_ID + 13	// Right channel volume before any adjustments are made.
#define DC_FIDELITY_VAR_KEY_THE_END							14							// Should always be last, with a value one higher than previous key ID.

#endif // !DC_FIDELITY_CONFIG




