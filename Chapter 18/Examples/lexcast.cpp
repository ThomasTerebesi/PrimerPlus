#include <iostream>
#include <string>
#include "boost/lexical_cast.hpp"	// please note that I did not include the boost files in the repository

int main()
{
	std::cout << "Enter your weight: ";
	float weight;
	std::cin >> weight;

	std::string gain = "A 10% increase raises ";
	std::string wt = boost::lexical_cast<std::string>(weight);

	gain = gain + wt + " to ";	// string operator+()
	weight = 1.1 * weight;

	gain = gain + boost::lexical_cast<std::string>(weight) + ".";

	std::cout << gain << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}