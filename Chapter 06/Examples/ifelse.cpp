#include <iostream>

int main()
{
	char ch;

	std::cout << "Type and I shall repeat." << std::endl;
	std::cin.get(ch);

	while (ch != '.')
	{
		if (ch == '\n')
			std::cout << ch;
		else
			std::cout << ++ch;	// conversion to int via (ch + 1)
		std::cin.get(ch);
	}

	std::cout << "\nPlease excuse the slight confusion.\n";

	std::cin.get();
	std::cin.get();

	return 0;
}