#include <iostream>
#include <sstream>
#include <string>

int main()
{
	std::string lit = "It was a dark and stormy day, and "
		" the full moon glowed brilliantly. ";

	std::istringstream instr(lit);	// use buf for input
	
	std::string word;

	while (instr >> word)			// read a word a time
		std::cout << word << std::endl;

	std::cin.get();

	return 0;
}