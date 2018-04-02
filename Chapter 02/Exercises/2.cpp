#include <iostream>

int main()
{
	std::cout << "Enter a distance in furlongs and I will convert it to yards: " << std::endl;
	float furlongs = 0.0f;
	std::cin >> furlongs;
	float yards = furlongs * 220.0f;
	std::cout << furlongs << " furlongs equals " << yards << " yards.";

	std::cin.get();
	std::cin.get();

	return 0;
}