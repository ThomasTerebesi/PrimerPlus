#include <iostream>

long double probability(unsigned int numbers, unsigned int picks);

int main()
{
	double total, choices;
	
	std::cout << "Enter the total number of choices on the game card and" << std::endl;
	std::cout << "the number of picks allowed:" << std::endl;

	while ((std::cin >> total >> choices) && choices <= total)
	{
		std::cout << "You have one chance in ";
		std::cout << probability(total, choices);
		std::cout << " of winning." << std::endl;
		std::cout << "Next two numbers (q to quit): ";
	}

	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();
	
	return 0;
}


// calculate the probability of picking picks numbers correctly
// from numbers choices
long double probability(unsigned int numbers, unsigned int picks)
{
	long double result = 1.0;
	long double n;
	unsigned int p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;

	return result;
}