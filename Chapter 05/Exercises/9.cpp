#include <iostream>
#include <string>
#include <ctime>

int main()
{
	std::cout << "Enter words (to stop, enter the word 'done'):" << std::endl;

	std::string inputWord;
	std::cin >> inputWord;

	unsigned short counter = 0;

	while (inputWord != "done")
	{
		counter++;
		std::cin >> inputWord;
	}

	std::cout << "You entered a total of " << counter << " words." << std::endl;

	float seconds = 3.0;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	clock_t start = clock();
	while (clock() - start < delay)
		;

	return 0;
}