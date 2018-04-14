#include <iostream>

const int MAX_FISH = 5;

int main()
{
	float fish[MAX_FISH];
	
	std::cout << "Please enter the weights of your fish." << std::endl;
	std::cout << "You may enter up to " << MAX_FISH << " fish <q to terminate>." << std::endl;
	
	std::cout << "Fish #1: ";
	
	int i = 0;
	while (i < MAX_FISH && std::cin >> fish[i])
	{
		if (++i < MAX_FISH)
			std::cout << "Fish #" << i + 1 << ": ";
	}

	float totalWeight = 0.0f;
	for (int j = 0; j < i; j++)
	{
		totalWeight += fish[j];
	}

	if (i == 0)
		std::cout << "You caught no fish." << std::endl;
	else
		std::cout << totalWeight / i << " = average weight of " << i << " fish." << std::endl;

	std::cout << "Done. Bye!" << std::endl;

	if (!std::cin)
	{
		std::cin.clear();
		std::cin.get();
	}

	std::cin.get();
	std::cin.get();
	
	return 0;
}