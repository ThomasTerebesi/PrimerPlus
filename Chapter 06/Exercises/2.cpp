#include <iostream>

const int ARRAY_SIZE = 10;

int main()
{
	double donations[ARRAY_SIZE];
	double sum = 0.0;
	unsigned short dCount;

	std::cout << "I will display interesting data after you entered up to 10 donations!\n";
	std::cout << "Any non-numeric value terminates input.\n" << std::endl;

	for (dCount = 0; dCount < ARRAY_SIZE; dCount++)
	{
		std::cout << "Enter donation #" << (dCount + 1) << ": $";
		if (!(std::cin >> donations[dCount]))
		{
			std::cin.clear();
			std::cin.get();
			std::cout << "\a\nInput terminated." << std::endl;
			break;
		}
		else
		{
			sum += donations[dCount];
		}
	}

	if (dCount > 0)
	{
		double average = sum / dCount;
		std::cout << "\nAverage donation: $" << average << std::endl;

		std::cout << "\nDonations greater than the average donation: " << std::endl;
		for (int i = 0; i < dCount; i++)
		{
			if (donations[i] > average)
			{
				std::cout << "Donation #" << (i + 1) << ": $" << donations[i] << "." << std::endl;
			}
		}
	}
	else
	{
		std::cout << "No valid input found." << std::endl;
	}

	std::cin.get();
	std::cin.get();

	return 0;
}