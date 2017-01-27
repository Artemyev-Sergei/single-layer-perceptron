#ifndef TRAININGSAMPLE_H
#define TRAININGSAMPLE_H

#include <vector>

class TrainingSample 
{
public:
	TrainingSample(bool expected_output, const std::vector<double> &inputs_)
		: output(expected_output), inputs(inputs_)
	{}

	bool get_output() const { return output; }
	std::vector<double> & get_inputs() { return inputs; }

private:
	bool output;
	std::vector<double> inputs;
};

#endif