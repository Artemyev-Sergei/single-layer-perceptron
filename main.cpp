#include "SLP_Examples.h"

int main()
try
{
	// TODO: Add menu
	ORPerceptron();
	ANDPerceptron();
	return 0;
}
catch(const std::invalid_argument& ia)
{
	std::cerr << ia.what();
}
catch (...)
{
	std::cerr << "Unknown exception!";
}