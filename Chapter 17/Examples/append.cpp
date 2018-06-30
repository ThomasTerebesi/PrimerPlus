#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const char * file = "guests.txt";

int main()
{
	char ch;

	// show initial contents
	std::ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		std::cout << "Here are the current contents of the " << file << " file:" << std::endl;
		while (fin.get(ch))
			std::cout << ch;
		fin.close();
	}

	// add new names
	std::ofstream fout(file, std::ios::out | std::ios::app);
	if (!fout.is_open())
	{
		std::cerr << "\a\nCan't open " << file << " file for output." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::cout << "\nEnter guest names (enter a blank line to quit):" << std::endl;
	std::string name;
	
	while (getline(std::cin, name) && name.size() > 0)
		fout << name << std::endl;

	fout.close();

	// show revised file
	fin.clear();	// not necessary for some compilers
	fin.open(file);
	if (fin.is_open())
	{
		std::cout << "Here are the new contents of the " << file << " file:" << std::endl;
		while (fin.get(ch))
			std::cout << ch;
		fin.close();
	}

	std::cout << "\nDone." << std::endl;

	std::cin.get();

	return 0;
}