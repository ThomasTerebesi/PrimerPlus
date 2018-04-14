#include <iostream>

const int ARRAY_SIZE = 80;

int main()
{
	char line[ARRAY_SIZE];

	int spaces = 0;

	std::cout << "Enter a line of text:\n";
	std::cin.get(line, ARRAY_SIZE);

	std::cout << "Complete line:\n" << line << std::endl;
	std::cout << "Line through first period:\n";

	for (int i = 0; line[i] != '\0'; i++)
	{
		std::cout << line[i]; // display the character

		if (line[i] == '.') // quit if the character is a period
			break;

		if (line[i] != ' ') // skip the rest of the loop if the character is a space
			continue;

		spaces++;
	}

	std::cout << "\nCounted " << spaces << " spaces." << std::endl;
	std::cout << "Done! Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}