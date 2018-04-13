#include <iostream>

const int ARRAY_SIZE = 6;

int main()
{
	float naaq[ARRAY_SIZE];

	std::cout << "Enter the NAAQs (New Age Awareness Quotients) "
			  << "of\nyour neighbors. Program terminates "
			  << "when you make\n" << ARRAY_SIZE << " entries "
			  << "or enter a negative value.\n";
	
	int i = 0;
	float temp;

	std::cout << "First value: ";
	std::cin >> temp;

	while (i < ARRAY_SIZE && temp >= 0)
	{
		naaq[i] = temp;
		++i;

		if (i < ARRAY_SIZE)
		{
			std::cout << "Next value: ";
			std::cin >> temp;
		}
	}

	if (i == 0)
		std::cout << "No data. Bye!\n";
	else
	{
		std::cout << "Enter your NAAQ: ";
		float you;
		std::cin >> you;
		int count = 0;

		for (int j = 0; j < i; j++)
			if (naaq[j] > you)
				++count;

		std::cout << count << " of your neighbors have greater awareness ";
		std::cout << "of the New Age than you do.\n";
	}

	std::cin.get();
	std::cin.get();
	return 0;
}