#include <iostream>

const int MAX_GOLF = 5;

int main()
{
	int golf[MAX_GOLF];

	std::cout << "Please enter your golf scores.\n";
	std::cout << "You must enter " << MAX_GOLF << " rounds." << std::endl;

	int i;
	for (i = 0; i < MAX_GOLF; i++)
	{
		std::cout << "Round #" << i + 1 << ": ";
		while (!(std::cin >> golf[i]))
		{
			std::cin.clear();
			
			while (std::cin.get() != '\n')
				continue;
			
			std::cout << "Please enter a number: ";
		}
	}

	float totalScores = 0.0f;

	for (i = 0; i < MAX_GOLF; i++)
		totalScores += static_cast<float>(golf[i]);

	std::cout << totalScores / MAX_GOLF << " = average score of " << MAX_GOLF << " rounds." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}