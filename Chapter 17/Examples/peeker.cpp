#include <iostream>
#include <ctime>

int main()
{
	// read and echo up to a # character
	char ch;

	while (std::cin.get(ch))		// terminates on EOF
	{
		if (ch != '#')
			std::cout << ch;
		else
		{
			std::cin.putback(ch);	// reinsert character
			break;
		}
	}

	if (!std::cin.eof())
	{
		std::cin.get(ch);
		std::cout << std::endl << ch << " is the next input character." << std::endl;
	}
	else
	{
		std::cout << "End of file reached." << std::endl;
		exit(0);
	}

	while (std::cin.peek() != '#')	// look ahead
	{
		std::cin.get(ch);
		std::cout << ch;
	}

	if (!std::cin.eof())
	{
		std::cin.get(ch);
		std::cout << std::endl << ch << " is the next input character." << std::endl;
	}
	else
		std::cout << "End of file reached." << std::endl;

	float seconds = 7.5f;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	clock_t start = clock();
	while (clock() - start < delay);

	return 0;
}