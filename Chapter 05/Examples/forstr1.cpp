#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter a word: ";
	std::string word;
	getline(std::cin, word);

	for (int i = word.size() - 1; i >= 0; i--)
		std::cout << word[i];

	std::cout << "\nBye.\n";

	std::cin.get();
	return 0;
}