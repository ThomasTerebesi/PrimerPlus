#include <iostream>

int main()
{
	std::cout << "The Amazing Accounto will sum and average five numbers for you." << std::endl;
	std::cout << "Please enter five values:\n";

	double number;
	double sum = 0.0;

	for (int i = 1; i <= 5; i++)
	{
		std::cout << "Value " << i << ": ";
		std::cin >> number;
		sum += number;
	}

	std::cout << "Five exquisit choices indeed! They sum to " << sum << std::endl;
	std::cout << "and average to " << sum / 5 << ".\n";
	std::cout << "The Amazing Accounto bids you adieu!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}