#include <iostream>
#include <cctype>

int main()
{
	std::cout << "Enter text for analysis, and type @ to terminate input." << std::endl;

	char ch;
	int chars = 0;
	int whitespace = 0;
	int digits = 0;
	int punct = 0;
	int others = 0;

	std::cin.get(ch);
	while (ch != '@')
	{
		if (isalpha(ch))
			chars++;
		else if (isspace(ch))
			whitespace++;
		else if (isdigit(ch))
			digits++;
		else if (ispunct(ch))
			punct++;
		else
			others++;
		
		std::cin.get(ch);
	}

	std::cout << chars << " letters, " << std::endl;
	std::cout << whitespace << " whitespace characters, " << std::endl;
	std::cout << digits << " digits, " << std::endl;
	std::cout << punct << " punctuation characters, " << std::endl;
	std::cout << digits << " other characters.\n" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}