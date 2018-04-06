#include <iostream>

int main()
{
	char ch = ' ';
	int count = 0;

	std::cout << "Enter characters; enter '#' to quit:\n";
	std::cin.get(ch);

	while (ch != '#')
	{
		std::cout << ch;
		++count;
		std::cin.get(ch);
	}

	std::cout << std::endl << count << " characters read." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}