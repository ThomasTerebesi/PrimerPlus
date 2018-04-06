#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter your first name: ";
	std::string firstName;
	getline(std::cin, firstName);

	std::cout << "Enter your last name: ";
	std::string lastName;
	getline(std::cin, lastName);

	std::string completeName = lastName + ", " + firstName;

	std::cout << "Here's the information in a single string: " << completeName << std::endl;

	std::cin.get();
	return 0;
}