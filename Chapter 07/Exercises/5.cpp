#include <iostream>

unsigned long long int RecFactorial(long long int n);

int main()
{
	long long int userNumber;

	std::cout << "Enter a positive integer to calculate its factorial ('q' to quit): ";

	while (std::cin >> userNumber)
	{
		std::cin.get();
		while (userNumber < 0)
		{
			std::cout << "\n\aInvalid input. Please enter a positive integer: ";
			std::cin >> userNumber;
		}

		std::cout << userNumber << "! = " << RecFactorial(userNumber);
		std::cout << "\n\nEnter another positive integer to calculate its factorial ('q' to quit): ";
	}

	return 0;
}

unsigned long long int RecFactorial(long long int n)
{
	if (n <= 1)
		return 1;
	else
	{
		return n * (RecFactorial(n - 1));
	}
}
