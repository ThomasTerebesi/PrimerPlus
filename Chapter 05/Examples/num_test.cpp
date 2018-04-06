#include <iostream>

int main()
{
	std::cout << "Enter the starting countdown value: ";
	int* limit = new int;
	std::cin >> *limit;

	int i;
	
	for (i = *limit; i; i--)
		std::cout << "i = " << i << "\n";

	std::cout << "Done, now that i = " << i << "." << std::endl;

	std::cin.get();
	std::cin.get();

	delete limit;

	return 0;
}