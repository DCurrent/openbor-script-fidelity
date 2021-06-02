#include "data/scripts/dc_fidelity/config.h"

/* 
* Category is the base level for seeking a sound. 
* Normally it is a model name, but can be anything.
*/

void dc_fidelity_get_member_category_list()
{
	char id;
	void result;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_CATEGORY;

	result = getglobalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_FIDELITY_DEFAULT_CATEGORY_LIST;
	}

	return result;
}

void dc_fidelity_set_member_category_list(void value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_CATEGORY;

	if (value == DC_FIDELITY_DEFAULT_CATEGORY_LIST)
	{
		value = NULL();
	}

	setglobalvar(id, value);
}
