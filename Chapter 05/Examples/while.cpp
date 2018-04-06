#include <iostream>

const int ARRAY_SIZE = 20;

int main()
{
	char name[ARRAY_SIZE];
	
	std::cout << "Enter your first name: ";
	std::cin >> name;
	std::cout << "Here is your name, ASCIIized:\n";

	int i = 0;
	while (name[i] != '\0') // while(name[i]) also possible
	{
		std::cout << name[i] << ": " << int(name[i]) << std::endl;
		i++;
	}

	std::cin.get();
	std::cin.get();
	return 0;
}