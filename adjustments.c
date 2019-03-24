#include "data/scripts/dc_fidelity/config.h"

// Caskey, Damon V. 
// 2018-10-13
//
// Return an adjusted volume based on position in screen. 
int dc_fidelity_volume_adjusted_horizontal(float position, int volume)
{
	float	center;
	float	result;
	float	factor;

	// Positions are absolute, so we need to subtract
	// the level scroll position to get where we 
	// are on the screen.
	position -= openborvariant("xpos");

	// Get median of the screen resolution.
	center = openborvariant("hResolution") * 0.5;

	// Divide position by center. This gives us a mutiplication
	// factor based on X posiition on screen:
	//
	// Far left, approaching 0.
	// Center, 1. 
	// Far right, approaching 2.
	factor = position / center;

	// Divide the orginal volume in half. We then mutiply by
	// our factor to produce an adjusted volume from left to
	// right:
	//
	// Far left, approaching 0.
	// Center, half volume.
	// Far right, approaching original volume.
	result = (volume / 2) * factor;

	// Return the result. 
	// -- Right channel: Use as is.
	// -- Left channel: Subtract from orginal channel volume.
	return result;
}