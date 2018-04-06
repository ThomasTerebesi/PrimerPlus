#include <iostream>
#include <ctime>

int main()
{
	char ch;
	int count = 0;

	while ((ch = std::cin.get()) != EOF)
	{
		std::cout << ch;
		++count;
	}

	std::cout << std::endl << count << " characters read." << std::endl;

	float seconds = 3.0;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	clock_t start = clock();
	while (clock() - start < delay)
		;

	return 0;
}