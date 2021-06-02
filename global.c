#include "data/scripts/dc_fidelity/config.h"

/* Try global category when specific category doesn't have sound type. */

void dc_fidelity_get_member_global_fallback()
{
	char id;
	void result;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_GLOBAL_FALLBACK;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_FIDELITY_DEFAULT_GLOBAL_FALLBACK;
	}

	return result;
}

void dc_fidelity_set_member_global_fallback(void value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_GLOBAL_FALLBACK;

	if (value == DC_FIDELITY_DEFAULT_GLOBAL_FALLBACK)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}
