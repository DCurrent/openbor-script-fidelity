#ifndef DC_FIDELITY_CONFIG

#include "data/scripts/dc_d20/main.c"

#define DC_FIDELITY_CONFIG 1

#define DC_FIDELITY_SAMPLE_INVALID			-1
#define DC_FIDELITY_FAILURE_LOG			0


// Default values.
#define DC_FIDELITY_DEFAULT_SOUND_CHANCE			1.0
#define DC_FIDELITY_DEFAULT_SOUND_LOCATION_BALANCE	0		// Adjust volume based on a given X position in relation to screen.
#define DC_FIDELITY_DEFAULT_SOUND_LOCATION_FADE	0		// Adjust volume based on a given Z position in relation to screen.
#define DC_FIDELITY_DEFAULT_SOUND_LOOP				0
#define DC_FIDELITY_DEFAULT_SOUND_PRIORITY			1
#define DC_FIDELITY_DEFAULT_SOUND_SPEED			100
#define DC_FIDELITY_DEFAULT_SOUND_VOLUME_LEFT		200
#define DC_FIDELITY_DEFAULT_SOUND_VOLUME_RIGHT		200

// Sound categories.
//
// Add as many as you like, but don't forget
// to give each new category a unique number ID.
// The order of category names and number IDs do 
// not matter at all. It also doesn't matter what the 
// numbers are for any one item. All that matters is
// that each one is unique. Just to keep things easier
// to read, I like to keep the names alphabetical
// and numbers consecutive, even if it means 
// re-numbering the whole list when I add something.

#define DC_FIDELITY_TYPE_VOICE_HEAVY_A		0	// Yalp, heavy attacks.
#define DC_FIDELITY_TYPE_VOICE_LIGHT_A		1	// Yalp, light attacks.
#define DC_FIDELITY_TYPE_VOICE_MEDIUM_A	2	// Yalp, medium attacks.

#define DC_FIDELITY_TYPE_WHIFF_HEAVY_A		3	// "Air" sound, heavy attacks.
#define DC_FIDELITY_TYPE_WHIFF_HEAVY_B		4	// "Air" sound, heavy attacks (blade).

#define DC_FIDELITY_TYPE_WHIFF_LIGHT_A		5	// "Air" sound, light attacks.
#define DC_FIDELITY_TYPE_WHIFF_LIGHT_B		6	// "Air" sound, light attacks (blade).

#define DC_FIDELITY_TYPE_WHIFF_MEDIUM_A	7	// "Air" sound, medium attacks.
#define DC_FIDELITY_TYPE_WHIFF_MEDIUM_B	8	// "Air" sound, medium attacks (blade).

// Indexes.
#define DC_FIDELITY_INDEX_RANDOM			-1	// Seek a random sound index from sound type.

// Variable keys.
#define DC_FIDELITY_VAR_KEY_SOUND_CHANCE				"dcsnd_0"
#define DC_FIDELITY_VAR_KEY_SOUND_ELEMENT				"dcsnd_1"
#define DC_FIDELITY_VAR_KEY_SOUND_ENTITY				"dcsnd_2"
#define DC_FIDELITY_VAR_KEY_SOUND_LOCATION_BALANCE		"dcsnd_3"
#define DC_FIDELITY_VAR_KEY_SOUND_LOCATION_FADE		"dcsnd_4"
#define DC_FIDELITY_VAR_KEY_SOUND_LOOP					"dcsnd_5"
#define DC_FIDELITY_VAR_KEY_SOUND_MODELS				"dcsnd_6"	// Global var used to store list of models -> types ->indexes.
#define DC_FIDELITY_VAR_KEY_SOUND_PRIORITY				"dcsnd_7"
#define DC_FIDELITY_VAR_KEY_SOUND_SPEED				"dcsnd_8"
#define DC_FIDELITY_VAR_KEY_SOUND_VOLUME_MAIN_LEFT		"dcsnd_9"	// Left channel volume before any adjustments are made.
#define DC_FIDELITY_VAR_KEY_SOUND_VOLUME_MAIN_RIGHT	"dcsnd_10"	// Right channel volume before any adjustments are made.

// Array element indexes.
#define DC_FIDELITY_ELEMENT_SAMPLES	0
#define DC_FIDELITY_ELEMENT_OVERRIDES	1

#endif // !DC_FIDELITY_CONFIG




