#include <iostream>
#include <fstream>
#include <cstdlib>

// COMMAND ARGUMENTS: 3_src.txt 3_dest.txt

int main(int argc, char * argv[])
{
	if (argc == 1)
	{
		std::cerr << "\aNo command line parameters were provided. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	else if (argc > 3)
	{
		std::cerr << "\aToo many command line parameters found. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	// open the source file
	std::ifstream fin;
	std::cout << "Opening source file '" << argv[1] << "'... ";
	fin.open(argv[1]);

	if (!fin.is_open())
	{
		std::cerr << "\n\aCould not open file. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::cout << "Done." << std::endl;

	// open the destination file
	std::ofstream fout;
	std::cout << "\nOpening destination file '" << argv[2] << "'... ";
	fout.open(argv[2]);

	if (!fout.is_open())
	{
		std::cerr << "\n\aCould not open file. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::cout << "Done." << std::endl;

	// write contents from source file to destination file
	char ch;

	while (fin.get(ch))
		fout.put(ch);

	std::cout << "\nDone." << std::endl;

	std::cin.get();

	fin.close();
	fout.close();

	return 0;
}