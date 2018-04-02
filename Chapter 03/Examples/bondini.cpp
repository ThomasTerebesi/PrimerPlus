#include <iostream>

int main()
{
	std::cout << "\aOperation \"HyperHype\" is now activated!\n";
	std::cout << "Enter your agent code: ________\b\b\b\b\b\b\b\b";
	int code;
	std::cin >> code;
	std::cout << "\aYou entered " << code << "...\n";
	std::cout << "Code verified! Proceed with Plan Z3!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}