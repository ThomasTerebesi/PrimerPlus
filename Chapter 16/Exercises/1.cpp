#include <iostream>
#include <string>

bool isPalindrome(const std::string & str);

int main()
{
	std::string input;
	
	std::cout << "Enter a word to check if it's a palindrome ('q' to quit): ";
	
	while (getline(std::cin,input) && input != "q")
	{
		if (isPalindrome(input))
			std::cout << "\t\"" << input << "\" is a palindrome." << std::endl;
		else
			std::cout << "\t\"" << input << "\" is no palindrome." << std::endl;

		std::cout << "\nEnter another word ('q' to quit): ";
	}

	return 0;
}

bool isPalindrome(const std::string & str)
{
	std::string reverse(str.rbegin(), str.rend());

	return str == reverse;
}
