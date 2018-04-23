#include <iostream>

long double probability(unsigned int numbers, unsigned int picks);

int main()
{
	unsigned int total, totalPowerball, choices, choicesPowerball;
	char ch;

	std::cout << "Enter the total number of choices on the game card and "; 
	std::cout << "the number of picks allowed ('q' to quit):" << std::endl;

	while ((std::cin >> total >> choices) && choices <= total)
	{
		std::cin.get();

		std::cout << "\nIs there a power ball ('y' or 'n')?" << std::endl;
		std::cin >> ch;

		if (ch == 'y')
		{
			std::cout << "\nEnter the total number of choices on the game card and ";
			std::cout << "the number of picks allowed for the power ball:" << std::endl;
			if (std::cin >> totalPowerball >> choicesPowerball)
			{
				std::cout << "You have 1 chance in ";
				std::cout << probability(total, choices) * probability(totalPowerball, choices);
				std::cout << " of winning." << std::endl;
			}
			else
			{
				std::cout << "\n\aInvalid input terminated." << std::endl;
				std::cin.clear();
				std::cin.get();
			}
		}
		else
		{
			std::cout << "You have 1 chance in ";
			std::cout << probability(total, choices);
			std::cout << " of winning." << std::endl;
		}

		std::cout << "\nEnter the total number of choices on the game card and ";
		std::cout << "the number of picks allowed ('q' to quit):" << std::endl;
	}

	return 0;
}


long double probability(unsigned int numbers, unsigned int picks)
{
	long double result = 1.0;
	long double n;
	unsigned int p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;

	return result;
}