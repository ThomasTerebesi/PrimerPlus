#include <iostream>
#include <cstring>

int main()
{
	char word[5] = "?ate";

	for (char ch = 'a'; std::strcmp(word, "mate"); ch++)
	{
		std::cout << word << std::endl;
		word[0] = ch;
	}

	std::cout << "After the loop ends, word is " << word << std::endl;

	std::cin.get();
	return 0;
}