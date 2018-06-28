#include <iostream>
#include <cstring>

int main()
{
	const char * state1 = "Florida";
	const char * state2 = "Kansas";
	const char * state3 = "Euphoria";

	int length = std::strlen(state2);

	std::cout << "Increasing loop index:" << std::endl;

	int i;
	for (i = 1; i <= length; i++)
	{
		std::cout.write(state2, i);
		std::cout << std::endl;
	}

	// concatenate output
	std::cout << "\nDecreasing loop index:" << std::endl;
	for (i = length; i > 0; i--)
		std::cout.write(state2, i) << std::endl;

	// exceed string length
	std::cout << "\nExceeding string length:" << std::endl;
	std::cout.write(state2, length + 5) << std::endl;
	
	std::cin.get();

	return 0;
}