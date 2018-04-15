#include <iostream>
#include <cctype>

int main()
{
	char ch;

	std::cout << "Enter characters and I will convert them." << std::endl;
	std::cout << "Execution stops when an '@' is found." << std::endl;


	std::cin.get(ch);
	while (ch != '@')
	{
		if (std::isupper(ch))
		{
			ch = std::tolower(ch);
		}
		else if (std::islower(ch))
		{
			ch = std::toupper(ch);
		}
		
		if (!std::isdigit(ch))
			std::cout << ch;
		
		std::cin.get(ch);
	}

	std::cout << "\nExecution stopped. Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}