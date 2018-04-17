#include <iostream>
#include <fstream>

const int SIZE = 64;

int main()
{
	// lorem.txt has exactly 155 characters
	char filename[SIZE];
	std::ifstream inFile;


	std::cout << "Enter a name of a text file: ";
	std::cin.getline(filename, SIZE);


	inFile.open(filename);
	if (!inFile.is_open())
	{
		std::cout << "Could not open the file " << filename << std::endl;
		std::cout << "Program terminating." << std::endl;

		std::cin.get();

		exit(EXIT_FAILURE);
	}


	unsigned int characters = 0;
	char ch;
	while (inFile.get(ch))
	{
		characters++;
	}


	if (inFile.eof())
	{
		std::cout << "End of file reached." << std::endl;
	}
	else if (inFile.fail())
		std::cout << "Input terminated by data mismatch." << std::endl;
	else
		std::cout << "Input terminated for unknown reason." << std::endl;


	if (characters == 0)
		std::cout << "No data processed." << std::endl;
	else
	{
		std::cout << "Total amount of characters found in " << filename << ": " << characters << std::endl;
	}


	inFile.close();

	std::cin.get();

	return 0;
}