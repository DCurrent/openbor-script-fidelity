#include "data/scripts/dc_fidelity/config.h"

// User config. These functions allow a module author to 
// temporarily override the default configuration as 
// needed. We use localvars, so any override is local 
// to the event that runs it and reset when the event
// is destroyed.

// Unless otherwise noted, any setting that does not 
// have a user value will fall back to its default 
// as defined in config.h

// Chance determines likelihood of sound function actually
// playing anything.
//
// 0.0 = Never
// 0.5 = 50%
// 1.0 = Always.
void dc_fidelity_set_sound_chance(float value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_SOUND_CHANCE, value);
}

void dc_fidelity_get_sound_chance()
{
	void result = getlocalvar(DC_FIDELITY_VAR_KEY_SOUND_CHANCE);

	if (!result)
	{
		result = DC_FIDELITY_DEFAULT_SOUND_CHANCE;
	}

	return result;
}

// Entity is the target entity when searching for
// a model to play sounds, an on screen location
// for stereo effects, and anything else that 
// requires a target entity reference. Defaults
// to the calling entity.
void dc_fidelity_set_entity(void value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_SOUND_ENTITY, value);
}

void dc_fidelity_get_entity()
{
	void result = getlocalvar(DC_FIDELITY_VAR_KEY_SOUND_ENTITY);

	if (!result)
	{
		result = getlocalvar("self");
	}

	return result;
}

// Element is the target item in sound indexes array. 
// Defaults to random, which causes a random element
// to be selected from all indexes available for
// a selected sound type.
void dc_fidelity_set_sound_element(int value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_SOUND_SPEED, value);
}

int dc_fidelity_get_sound_element()
{
	int result = getlocalvar(DC_FIDELITY_VAR_KEY_SOUND_ELEMENT);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_INDEX_RANDOM;
	}

	return result;
}

// Enables auto balance. As a location moves horizontaly
// in relation to screen position, volume balance is 
// adjusted to create a true location based stereo
// effect.
void dc_fidelity_set_sound_location_balance(int value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_SOUND_LOCATION_BALANCE, value);
}

int dc_fidelity_get_sound_location_balance()
{
	int result = getlocalvar(DC_FIDELITY_VAR_KEY_SOUND_LOCATION_BALANCE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_LOCATION_BALANCE;
	}

	return result;
}

// Enables auto fade. As a location moves lateraly
// in relation to screen position, volume is adjusted
// to create a distance based fade effect.
void dc_fidelity_set_sound_location_fade(int value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_SOUND_LOCATION_FADE, value);
}

int dc_fidelity_get_sound_location_fade()
{
	int result = getlocalvar(DC_FIDELITY_VAR_KEY_SOUND_LOCATION_FADE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_LOCATION_FADE;
	}

	return result;
}

// Sound looping on playback.
void dc_fidelity_set_sound_loop(int value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_SOUND_LOOP, value);
}

int dc_fidelity_get_sound_loop()
{
	int result = getlocalvar(DC_FIDELITY_VAR_KEY_SOUND_LOOP);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_LOOP;
	}

	return result;
}

// Priority of sound when played on same channel.
void dc_fidelity_set_sound_priority(int value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_SOUND_PRIORITY, value);
}

int dc_fidelity_get_sound_priority()
{
	int result = getlocalvar(DC_FIDELITY_VAR_KEY_SOUND_PRIORITY);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_PRIORITY;
	}

	return result;
}

// Speed is the playback speed for sounds before any auto
// adjustments are made. Generally, slower playback speeds
// result in a lower pitch. As an example of this effect, 
// OpenBOR’s native sound effect system plays hit impact 
// sounds at lower speeds as greater damage is inflicted. 
void dc_fidelity_set_sound_speed(int value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_SOUND_SPEED, value);
}

// Get specified speed, or default if not available.
int dc_fidelity_get_sound_speed()
{
	int result = getlocalvar(DC_FIDELITY_VAR_KEY_SOUND_SPEED);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_SPEED;
	}

	return result;
}

// Volume is the intitial left and right channel 
// playback volume before any auto adjustments
// are made. 
void dc_fidelity_set_sound_volume_main_left(int value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_SOUND_VOLUME_MAIN_LEFT, value);
}

int dc_fidelity_get_sound_volume_main_left()
{
	int result = getlocalvar(DC_FIDELITY_VAR_KEY_SOUND_VOLUME_MAIN_LEFT);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_VOLUME_LEFT;
	}

	return result;
}

void dc_fidelity_set_sound_volume_main_right(int value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_SOUND_VOLUME_MAIN_RIGHT, value);
}

int dc_fidelity_get_sound_volume_main_right()
{
	int result = getlocalvar(DC_FIDELITY_VAR_KEY_SOUND_VOLUME_MAIN_RIGHT);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_VOLUME_RIGHT;
	}

	return result;
}

