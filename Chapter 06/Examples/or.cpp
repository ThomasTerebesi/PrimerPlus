#include <iostream>

int main()
{
	std::cout << 
		"This program may reformat your hard disk\n"
		"and destroy all your data.\n"
		"Do you wish to continue? <y/n> ";

	char ch;
	std::cin >> ch;

	if (ch == 'y' || ch == 'Y')
		std::cout << "You were warned!\a\a\n";
	else if (ch == 'n' || ch == 'N')
		std::cout << "A wise choice ... Bye!\n";
	else
		std::cout <<
			"That wasn't a y or an n! Apparently you "
			"can't follow\ninstructions, so I'll "
			"trash your disk anyway.\a\a\a\n";

	std::cin.get();
	std::cin.get();
	return 0;
}