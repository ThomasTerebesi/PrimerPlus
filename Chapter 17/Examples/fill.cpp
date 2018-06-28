#include <iostream>

int main()
{
	std::cout.fill('*');
	const char * staff[2] = { "Waldo Whipsnade", "Wilmarie Wooper" };
	long bonus[2] = { 900, 1350 };

	for (int i = 0; i < 2; i++)
	{
		std::cout << staff[i] << ": $";
		std::cout.width(7);
		std::cout << bonus[i] << std::endl;
	}

	std::cin.get();

	return 0;
}