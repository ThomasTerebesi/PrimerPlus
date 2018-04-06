#include <iostream>
#include <string>

int main()
{
	std::string word = "?ate";

	for (char ch = 'a'; word != "mate"; ch++)
	{
		std::cout << word << std::endl;
		word[0] = ch;
	}

	std::cout << "After the loop ends, word is " << word << std::endl;

	std::cin.get();
	return 0;
}