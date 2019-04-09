#ifndef DC_FIDELITY_CONFIG

#include "data/scripts/dc_d20/main.c"

#define DC_FIDELITY_CONFIG 1

// Name of library. Used mainly as a base for variable IDs. Must
// be unique vs all other libraries. Try to keep it short.
#define DC_FIDELITY_BASE_ID	 "dcfid"

// Sound Categories
//
// Normally sound categories are assigned to a
// model name. When an entity is instructed to play
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
// Note: GLOBAL is a special category used as a default
// fallback (you can switch this behavior off). If a 
// sound type does not exist for the requested category,
// the sound system will look for that type in the global
// category instead. If the type is not found in global
// category either, no sound is played.
#define DC_FIDELITY_CATEGORY_GLOBAL			"global"
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

#define DC_FIDELITY_TYPE_VOICE_HEAVY_A		0	// Yalp, heavy attacks.
#define DC_FIDELITY_TYPE_VOICE_LIGHT_A		1	// Yalp, light attacks.
#define DC_FIDELITY_TYPE_VOICE_MEDIUM_A		2	// Yalp, medium attacks.

#define DC_FIDELITY_TYPE_WHIFF_HEAVY_A		3	// "Air" sound, heavy attacks.
#define DC_FIDELITY_TYPE_WHIFF_HEAVY_B		4	// "Air" sound, heavy attacks (blade).

#define DC_FIDELITY_TYPE_WHIFF_LIGHT_A		5	// "Air" sound, light attacks.
#define DC_FIDELITY_TYPE_WHIFF_LIGHT_B		6	// "Air" sound, light attacks (blade).

#define DC_FIDELITY_TYPE_WHIFF_MEDIUM_A		7	// "Air" sound, medium attacks.
#define DC_FIDELITY_TYPE_WHIFF_MEDIUM_B		8	// "Air" sound, medium attacks (blade).

#define DC_FIDELITY_TYPE_SPAWN_A			9	// Spawn sound.

// Options.
#define DC_FIDELITY_INDEX_RANDOM			-1		// Seek a random sound index from sound type.
#define DC_FIDELITY_SAMPLE_INVALID			-1
#define DC_FIDELITY_FAILURE_LOG				0

// Default values.
#define DC_FIDELITY_DEFAULT_INSTANCE						0
#define DC_FIDELITY_DEFAULT_ENT								getlocalvar("self")
#define DC_FIDELITY_DEFAULT_MODELS							NULL()
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
#define DC_FIDELITY_VAR_KEY_SOUND_CHANCE					DC_FIDELITY_BASE_ID + 2
#define DC_FIDELITY_VAR_KEY_SOUND_ELEMENT					DC_FIDELITY_BASE_ID + 3
#define DC_FIDELITY_VAR_KEY_SOUND_ENTITY					DC_FIDELITY_BASE_ID + 4
#define DC_FIDELITY_VAR_KEY_SOUND_LOCATION_BALANCE			DC_FIDELITY_BASE_ID + 5
#define DC_FIDELITY_VAR_KEY_SOUND_LOCATION_FADE				DC_FIDELITY_BASE_ID + 6
#define DC_FIDELITY_VAR_KEY_SOUND_LOOP						DC_FIDELITY_BASE_ID + 7
#define DC_FIDELITY_VAR_KEY_SOUND_CATEGORY					DC_FIDELITY_BASE_ID + 8		// Global var used to store list of models -> types ->indexes.
#define DC_FIDELITY_VAR_KEY_SOUND_PRIORITY					DC_FIDELITY_BASE_ID + 9
#define DC_FIDELITY_VAR_KEY_SOUND_SPEED						DC_FIDELITY_BASE_ID + 10
#define DC_FIDELITY_VAR_KEY_SOUND_VOLUME_MAIN_LEFT			DC_FIDELITY_BASE_ID + 11	// Left channel volume before any adjustments are made.
#define DC_FIDELITY_VAR_KEY_SOUND_VOLUME_MAIN_RIGHT			DC_FIDELITY_BASE_ID + 12	// Right channel volume before any adjustments are made.
#define DC_FIDELITY_VAR_KEY_THE_END							12							// Should always be last, with a value one higher than previous key ID.

#endif // !DC_FIDELITY_CONFIG




