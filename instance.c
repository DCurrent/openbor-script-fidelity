#include "data/scripts/dc_fidelity/config.h"

// Which instance is in use?
int dc_fidelity_get_instance()
{
	void result = getlocalvar(DC_FIDELITY_VAR_KEY_INSTANCE);

	if (!result)
	{
		result = DC_FIDELITY_DEFAULT_INSTANCE;
	}

	return result;
}

void dc_fidelity_set_instance(int value)
{
	setlocalvar(DC_FIDELITY_VAR_KEY_INSTANCE, value);
}

// Caskey, Damon V.
// 2018-11-22
//
// Clears the current instance, effectively resetting
// all values to their defaults.
void dc_fidelity_reset_instance()
{
	int instance;

	// Get instance.
	instance = dc_fidelity_get_instance();

	// Destroy all instance variables.
	dc_fidelity_free_instance();

	// If the instance ID isn't default, then restore 
	// it to memory. Either way we now have a clean
	// copy of the current instance.
	if (instance != DC_FIDELITY_DEFAULT_INSTANCE)
	{
		dc_fidelity_set_instance(instance);
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Destroy the current instance by deleting all
// library variables.
void dc_fidelity_free_instance()
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_fidelity_get_instance();

	// Loop from 0 to end count of library variables.
	for (i = 0; i < DC_FIDELITY_VAR_KEY_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_FIDELITY_VAR_KEY_BASE_ID + i;

		// Delete variable.
		setlocalvar(id, NULL());
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Send all library variables to log for debugging.
void dc_fidelity_dump_instance()
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_fidelity_get_instance();

	// Log base name and instance.
	log("\n\n " + DC_FIDELITY_VAR_KEY_BASE_ID + " dump:");
	log("\n\t " + "Instance: " + instance);

	// Loop from 0 to end count of instance variables.
	for (i = 0; i < DC_FIDELITY_VAR_KEY_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_FIDELITY_VAR_KEY_BASE_ID + i;

		// Log ID.
		log("\n\t " + id + ": ");

		// Log value.
		log(getlocalvar(id));
	}

	// Log end point.
	log("\n End Dump.\n");
}