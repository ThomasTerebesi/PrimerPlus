#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
	std::ifstream fin;
	fin.open("tobuy.txt");

	if (fin.is_open() == false)
	{
		std::cerr << "Can't open file. Bye." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::string item;
	
	int count = 0;

	getline(fin, item, ':');

	while (fin)	// while input is good
	{
		++count;
		std::cout << count << ": " << item << std::endl;
		getline(fin, item, ':');
	}

	std::cout << "Done." << std::endl;

	fin.close();

	std::cin.get();

	return 0;
}