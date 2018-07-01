#include <iostream>

int main()
{
	std::cout << "Enter a string and I will count the number of characters up to the first '$' character:" << std::endl;
	
	char ch;
	std::cin.get(ch);

	unsigned short charCount = 0;

	while (ch != '$')
	{
		charCount++;
		std::cin.get(ch);
	}

	std::cin.putback(ch);

	std::cout << "The string you entered has " << charCount << " characters up to the first '$' character." << std::endl;
	std::cout << "The next character in the input stream is '" << static_cast<char>(std::cin.get()) << "'." << std::endl;

	while (std::cin.get() != '\n')
		continue;

	std::cin.get();

	return 0;
}