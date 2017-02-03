#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <numeric>
#include <stdexcept>
#include "TrainingSample.h"

class Perceptron
{
public:
	Perceptron(int input_neuron_count, const double learning_rate_, const double threshold_)
		: weights(input_neuron_count), learning_rate(learning_rate_), threshold(threshold_)
	{}

	// Actual training algorithm.
	void train(std::vector<TrainingSample>& training_set, unsigned int max_iterations)
	{
		if (max_iterations <= 0)
			throw std::invalid_argument("The maximum number of iterations can not be less or equal to zero!");

		unsigned int iterations(0);
		while (true)
		{
			if (iterations > max_iterations)
				break;
			else
				++iterations;

			int error_count = 0;
			for (auto &sample : training_set) 
			{
				bool output = learn(sample.get_output(), sample.get_inputs());	// Correcting weights depending on the result of 
												// the comparison between a dot product and a threshold.
												// output is a dot product value here.
				if (output != sample.get_output())
				{
					std::cout << "Incorrect on { " << sample.get_inputs()[0] << "  " << sample.get_inputs()[1] << " } Perceptron output was " << std::boolalpha << output << std::endl;
					++error_count;
				}
				else
				{
					std::cout << "Correct on { " << sample.get_inputs()[0] << "  " << sample.get_inputs()[1] << " } Perceptron output was " << std::boolalpha << output << std::endl;
				}
			}

			if (error_count == 0)
				break;
		}
	}

	// Adjusting weights.
	// Note: expected means teaching, i.e. teaching input.
	bool learn(bool expected_result, const std::vector<double> &inputs)
	{
		bool result = get_result(inputs);

		if (result != expected_result) 
		{
			double error = (expected_result ? 1 : 0) - (result ? 1 : 0);	// Converting bool to double.
			for (size_t i = 0; i < weights.size(); ++i) 
			{
				weights[i] += learning_rate * error * inputs[i];			// Delta rule.
				std::cout << "weights[i]: " << weights[i] << std::endl;
			}
		}
		return result;
	}

	// Comparison of a dot product and a threshold, i.e a perceptron output.
	bool get_result(const std::vector<double> &inputs)
	{
		if (inputs.size() != weights.size())
			throw std::invalid_argument("Invalid number of inputs for a training set or for a perceptron!");

		return dot_product(inputs, weights) > threshold;
	}

private:
	double learning_rate;
	double threshold;
	std::vector<double> weights;

	// The weighted sum is interpreted as a dot product.
	double dot_product(const std::vector<double> &v1, const std::vector<double> &v2)
	{
		return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0.0);
	}
};

#endif
