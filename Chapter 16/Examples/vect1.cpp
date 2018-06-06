#include <iostream>
#include <string>
#include <vector>

const int NUM = 5;

int main()
{
	std::vector<int> ratings(NUM);
	std::vector<std::string> titles(NUM);

	std::cout << "You will do exactly as told. You will enter" << std::endl;
	std::cout << NUM << " book titles and your ratings (0 - 10)." << std::endl;

	int i;
	for (i = 0; i < NUM; i++)
	{
		std::cout << "\nEnter title #" << (i + 1) << ": ";
		getline(std::cin, titles[i]);
		std::cout << "Enter your rating for " << titles[i] << " (0 - 10): ";
		std::cin >> ratings[i];
		std::cin.get();
	}

	std::cout << "\nThank you. You entered the following:" << std::endl;
	std::cout << "Rating\tBook\t" << std::endl;

	for (i = 0; i < NUM; i++)
	{
		std::cout << ratings[i] << "\t" << titles[i] << std::endl;
	}

	std::cin.get();

	return 0;
}