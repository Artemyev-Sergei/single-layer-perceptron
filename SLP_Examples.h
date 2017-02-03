#ifndef SLP_EXAMPLES_H
#define SLP_EXAMPLES_H

#include <iostream>
#include <cassert>
#include "Perceptron.h"

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

	// Threshhold is 0.5!
	Perceptron slp(2, 0.2, 0.5);

	// Let's train our network.
	slp.train(training_set, 5);

	// Let's verify it.
	assert(slp.get_result({ 0, 0 }) == false);
	assert(slp.get_result({ 0, 1 }) == true);
	assert(slp.get_result({ 1, 0 }) == true);
	assert(slp.get_result({ 1, 1 }) == true);
	std::cout << "OR Perceptron is successfully trained!" << std::endl;
}

void ANDPerceptron()
{
	std::cout << "Training AND Perceptron..." << std::endl;

	// Training set for AND function.
	std::vector<TrainingSample> training_set =
	{
		TrainingSample(false,{ 0, 0 }),
		TrainingSample(false,{ 0, 1 }),
		TrainingSample(false,{ 1, 0 }),
		TrainingSample(true,{ 1, 1 })
	};

	// Threshhold is 1.5!
	Perceptron slp(2, 0.2, 1.5);

	// Let's train our network.
	slp.train(training_set, 5);

	// Let's verify it.
	assert(slp.get_result({ 0, 0 }) == false);
	assert(slp.get_result({ 0, 1 }) == false);
	assert(slp.get_result({ 1, 0 }) == false);
	assert(slp.get_result({ 1, 1 }) == true);
	std::cout << "AND Perceptron is successfully trained!" << std::endl;
}

#endif
