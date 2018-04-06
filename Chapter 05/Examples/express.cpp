#include <iostream>

int main()
{
	int x;

	std::cout << "The expression x = 100 has the value ";
	std::cout << (x = 100) << std::endl; // "side effect"
	std::cout << "Now x = " << x << std::endl;

	std::cout << "The expression x < 3 has the value ";
	std::cout << (x < 3) << std::endl;

	std::cout << "The expression x > 3 has the value ";
	std::cout << (x > 3) << std::endl;

	std::cout.setf(std::ios_base::boolalpha);

	std::cout << "The expression x < 3 has the value ";
	std::cout << (x < 3) << std::endl;

	std::cout << "The expression x > 3 has the value ";
	std::cout << (x > 3) << std::endl;

	std::cin.get();
	return 0;
}