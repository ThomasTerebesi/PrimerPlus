#include <iostream>
#include <cmath>

int main()
{
	float area;
	std::cout << "Enter the floor area, in square feet, of your home: ";
	std::cin >> area;
	float side = sqrt(area);
	std::cout << "That's the equivalent of a square " << side
		<< " feet to the side." << std::endl;
	std::cout << "How fascinating!" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}