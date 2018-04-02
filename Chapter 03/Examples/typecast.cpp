#include <iostream>

int main()
{
	int auks, bats, coots;

	// add double values and convert the result to int via assignment
	auks = 19.99 + 11.99;
	

	bats = (int) 19.99 + (int) 11.99; // C syntax
	coots = int(19.99) + int(11.99); // C++ syntax
	std::cout << "auks = " << auks << std::endl;
	std::cout << "bats = " << bats << std::endl;
	std::cout << "coots = " << coots << std::endl << std::endl;

	char ch = 'Z';
	std::cout << "The code for " << ch << " is " << int(ch) << std::endl;
	std::cout << "Yes, the code is " << static_cast<int>(ch) << std::endl;

	std::cin.get();
	return 0;
}