#include <iostream>
#include <array>

int main()
{
	std::array<float, 3> dashResults;
	
	std::cout << "Enter the first result: ";
	std::cin >> dashResults[0];

	std::cout << "Enter the second result: ";
	std::cin >> dashResults[1];

	std::cout << "Enter the third result: ";
	std::cin >> dashResults[2];

	std::cout << "\nFirst dash time: " << dashResults[0] << std::endl;
	std::cout << "Second dash time: " << dashResults[1] << std::endl;
	std::cout << "Third dash time: " << dashResults[2] << std::endl;

	std::cout << "\nAverage dash time: ";
	std::cout << (dashResults[0] + dashResults[1] + dashResults[2]) / dashResults.size() << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}