#ifndef SLP_EXAMPLES_H
#define SLP_EXAMPLES_H

#include <iostream>
#include <cassert>
#include "Perceptron.h"

// TODO: Add other binary functions

void ORPerceptron()
{
	std::cout << "Training OR Perceptron..." << std::endl;

	// Training set for OR function.
	std::vector<TrainingSample> training_set =
	{
		TrainingSample(false,{ 0, 0 }),
		TrainingSample(true,{ 0, 1 }),
		TrainingSample(true,{ 1, 0 }),
		TrainingSample(true,{ 1, 1 })
	};

	// Two Input Neurons and One Output.
	Perceptron slp(2);	// Note: The first argument is for the number of weights or neurons, metaphorically speaking.

	// Let's train our network.
	slp.train(training_set, 14);	// Note: The second argument is for the number of iterations!

	// Let's verify it.
	assert(slp.get_result({ 0, 0 }) == false);
	assert(slp.get_result({ 0, 1 }) == true);
	assert(slp.get_result({ 1, 0 }) == true);
	assert(slp.get_result({ 1, 1 }) == true);
	std::cout << "Successfully trained!" << std::endl;
}

#endif