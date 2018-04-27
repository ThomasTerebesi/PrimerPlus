#include <iostream>
#include <string>

void CaptainCapsLock(std::string & string);

int main()
{
	std::string inputString;
	std::cout << "Enter a string ('q' to quit): ";
	getline(std::cin, inputString);

	while (inputString != "q")
	{
		CaptainCapsLock(inputString);
		std::cout << inputString << std::endl;
		std::cout << "Next string ('q' to quit): ";
		getline(std::cin, inputString);
	}

	std::cout << "Bye!" << std::endl;

	std::cin.get();

	return 0;
}

void CaptainCapsLock(std::string & string)
{
	for (unsigned int i = 0; i < string.size(); i++)
		string[i] = toupper(string[i]);
}
