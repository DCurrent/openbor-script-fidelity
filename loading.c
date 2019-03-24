#include "data/scripts/dc_fidelity/config.h"

#import "data/scripts/dc_fidelity/config.c"
#import "data/scripts/dc_fidelity/instance.c"
#import "data/scripts/dc_fidelity/model.c"

void dc_fidelity_setup(char model, int type, char file)
{
	void models;	// Key - model, Value - Sound types array.
	void types;		// Key - Sound Type, Value - Sound index array.
	void indexes;	// Key - Numeric, Value - Sound file index.
	int  sample_id;	// Sample ID loaded to element.
	
	int size;	// Array size.
	int i;		// Loop index.

	// Get the model's list array.
	models = dc_fidelity_get_model_list();

	// Initialize array if it doesn't exist.
	if (!models)
	{
		// Create the array.
		models = array(0);

		// Store pointer to array in a globalvar for
		// future access.
		dc_fidelity_set_model_list(models);
	}

	// Get array of sound types for a model.
	types = get(models, model);

	// Initialize array if it doesn't exist.
	if (!types)
	{
		// Create the array.
		types = array(0);

		// Store pointer to array in an element of
		// the parent array.
		set(models, model, types);
	}

	// Get array of sound indexes for a sound type.
	indexes = get(types, type);

	// Initialize array if it doesn't exist.
	if (!indexes)
	{
		// Create the array.
		indexes = array(0);

		// Store pointer to array in an element of
		// the parent array.
		set(types, type, indexes);
	}

	// Get the array size, we can use this as
	// the index since we want to add an element.
	size = size(indexes);

	// Load the sample and get ID.
	sample_id	= loadsample(file);

	// Add new array element and populate its
	// value with sample ID.
	add(indexes, size, sample_id);

	// Output to the log.
	log("\n Sound sample loaded: ");
	log("\n");
	log("\t");
	log("Model:\t\t" + model);
	log("\n");
	log("\t");
	log("Type:\t\t" + type);
	log("\n");
	log("\t");
	log("Index:\t\t" + size);
	log("\n");
	log("\t");
	log("Sample ID:\t" + sample_id);
	log("\n");
}

// Caskey, Damon V.
// 2018-10-22
// 
// Test if a sound loaded properly.
void dc_fidelity_loaded_test(char model, int type, int index)
{
	void models;	// Key - model, Value - Sound types array.
	void types;		// Key - Sound Type, Value - Sound index array.
	void indexes;	// Key - Numeric, Value - Sound file index.
	char id;		// ID key for variables.

	id = dc_fidelity_get_instance() + DC_FIDELITY_VAR_KEY_SOUND_MODELS;

	// Get the model's list array.
	models = getglobalvar(id);

	// Get array of sound types for a model.
	types = get(models, model);

	// Get array of sound indexes for a sound type.
	indexes = get(types, type);

	// Get array of sound indexes for a sound type.
	index = get(indexes, index);

	log("\n\n dc_fidelity_loaded_test");
	log("\n");
	
	log("\t");
	log("Models Array: " + models);
	log("\n");

	log("\t");
	log("Types Array: " + types);
	log("\n");

	log("\t");
	log("Indexes Array: " + indexes);
	log("\n");

	log("\t");
	log("Sound index: " + index);
	log("\n");

	playsample(index, DC_FIDELITY_DEFAULT_SOUND_PRIORITY, DC_FIDELITY_DEFAULT_SOUND_VOLUME_LEFT, DC_FIDELITY_DEFAULT_SOUND_VOLUME_RIGHT, DC_FIDELITY_DEFAULT_SOUND_SPEED, DC_FIDELITY_DEFAULT_SOUND_LOOP);
}