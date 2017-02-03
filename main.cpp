#include <string>
#include "SLP_Examples.h"

static void show_usage(std::string name)
{
	std::cerr << "Usage: " << name << " <option>\n"
		<< "Options:\n"
		<< "\thelp\t\tShow this help message\n"
		<< "\tORPerceptron\tSee how ORPerceptron works\n"
		<< "\tANDPerceptron\tSee how ANDPerceptron works\n"
		<< std::endl;
}

int main(int argc, char *argv[])
try
{
	// Check the number of input parameters
	if (argc < 2 || std::string(argv[1]) == "help")
	{
		// Tell the user how to run the program
		show_usage(argv[0]);
		return 1;
	}
	else if (std::string(argv[1]) == "ORPerceptron")
	{
		ORPerceptron();
	}
	else if (std::string(argv[1]) == "ANDPerceptron")
	{
		ANDPerceptron();
	}

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
