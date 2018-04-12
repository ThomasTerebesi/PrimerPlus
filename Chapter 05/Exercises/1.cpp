#include <iostream>

int main()
{
	std::cout << "I will add all integers from a lower limit through an upper limit." << std::endl;

	std::cout << "Enter a lower limit: ";
	int* lowerLimit = new int;
	std::cin >> *lowerLimit;

	std::cout << "Enter an upper limit: ";
	int*  upperLimit = new int;
	std::cin >> *upperLimit;

	int* result = new int;
	*result = 0;
	for (int i = *lowerLimit; i <= *upperLimit; i++)
	{
		*result += i;
	}
	std::cout << "The sum of all integers from " << *lowerLimit << " through " << *upperLimit << " is " << *result << "." << std::endl;

	std::cin.get();
	std::cin.get();

	delete lowerLimit, upperLimit, result;

	return 0;
}