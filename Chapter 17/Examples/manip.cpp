#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int n;
	std::cin >> n;

	std::cout << "\nn\t\tn*n" << std::endl;
	std::cout << n << "\t\t" << n * n << "\t(decimal)" << std::endl;

	// set to hex mode
	std::cout << std::hex;
	std::cout << n << "\t\t" << n * n << "\t(hexadecimal)" << std::endl;

	// set to octal mode
	std::cout << std::oct << n << "\t\t" << n * n << "\t(hexadecimal)" << std::endl;

	// alternative way to call a manipulator
	std::dec(std::cout);
	std::cout << n << "\t\t" << n * n << "\t(decimal)" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}