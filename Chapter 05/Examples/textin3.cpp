#include <iostream>
#include <ctime>

int main()
{
	char ch;
	int count = 0;
	std::cin.get(ch);

	while (std::cin.fail() == false)
	{
		std::cout << ch;
		++count;
		std::cin.get(ch);
	}

	std::cout << std::endl << count << " characters read." << std::endl;

	float seconds = 3.0;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	clock_t start = clock();
	while (clock() - start < delay)
		;

	return 0;
}