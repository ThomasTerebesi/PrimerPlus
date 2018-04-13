#include <iostream>

int main()
{
	int a, b;
	
	std::cout << "Enter two integers: ";
	std::cin >> a >> b;

	std::cout << "The larger integer of " << a << " and " << b;
	int c = a > b ? a : b;
	std::cout << " is " << c << "." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}