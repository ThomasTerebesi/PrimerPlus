#include <iostream>
#include <cstring>
#include <ctime>

const unsigned short STRING_LENGTH = 32;

int main()
{
	std::cout << "Enter words (to stop, enter the word 'done'):" << std::endl;
	
	char inputWord[STRING_LENGTH];
	std::cin >> inputWord;

	unsigned short counter = 0;

	while (std::strcmp(inputWord, "done"))
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