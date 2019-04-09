#include "data/scripts/dc_fidelity/config.h"

#import "data/scripts/dc_fidelity/instance.c"

// Get
void dc_fidelity_get_category_list()
{
	char id;
	void result;

	// Get id key.
	id = dc_fidelity_get_instance() + DC_FIDELITY_VAR_KEY_SOUND_CATEGORY;

	result = getglobalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_FIDELITY_DEFAULT_CATEGORY_LIST;
	}

	return result;
}

// Set
void dc_fidelity_set_model_list(void value)
{
	char id;

	// Get id key.
	id = dc_fidelity_get_instance() + DC_FIDELITY_VAR_KEY_SOUND_CATEGORY;

	// If the value is same as default, then use
	// make sure variable is deleted instead. We fall
	// back to default for empty vars, so may as
	// well save the memory.
	if (value == DC_FIDELITY_DEFAULT_CATEGORY_LIST)
	{
		value = NULL();
	}

	setglobalvar(id, value);
}

void dc_fidelity_initialize_category_list()
{

}