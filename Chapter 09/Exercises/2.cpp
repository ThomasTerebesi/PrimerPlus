#include <iostream>
#include <string>

void StrCount(std::string &str);

int main()
{
	std::string input;

	std::cout << "Enter a line:" << std::endl;
	getline(std::cin, input);

	while (std::cin) 
	{
		if (input == "")
		{
			std::cout << "Input terminated by user." << std::endl;
			break;
		}

		StrCount(input);

		std::cout << "\nEnter next line (empty line to quit):" << std::endl;
		getline(std::cin, input);
	}

	std::cout << "Bye!" << std::endl;

	std::cin.get();

	return 0;
}

void StrCount(std::string &str)
{
	static int total = 0;

	std::cout << "\"" << str << "\" contains ";
	
	total += str.length();

	std::cout << str.length() << " characters." << std::endl;
	std::cout << total << " characters total." << std::endl;
}
