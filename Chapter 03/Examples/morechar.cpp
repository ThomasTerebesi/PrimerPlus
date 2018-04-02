#include <iostream>

int main()
{
	char ch = 'M';
	int i = ch;
	std::cout << "The ASCII code for " << ch << " is " << i << "." << std::endl;

	std::cout << "Add one to the character code: " << std::endl;
	ch = ch + 1;
	i = ch;
	std::cout << "The ASCII code for " << ch << " is " << i << "." << std::endl;

	std::cout << "Displaying char ch using cout.put(ch): ";
	std::cout.put(ch);

	std::cout.put('!');
	
	std::cout << std::endl << "Done." << std::endl;

	std::cin.get();
	return 0;
}