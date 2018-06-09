#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string letters;
	std::cout << "Enter the letter grouping ('quit' to quit): ";

	while (std::cin >> letters && letters != "quit")
	{
		std::cout << "Permutations of " << letters << ":" << std::endl;
		sort(letters.begin(), letters.end());
		std::cout << letters << std::endl;
		while (next_permutation(letters.begin(), letters.end()))
			std::cout << letters << std::endl;

		std::cout << "\nEnter next sequence ('quit' to quit): ";
	}

	std::cout << "\nDone." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}