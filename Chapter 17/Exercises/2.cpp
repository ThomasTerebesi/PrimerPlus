#include <iostream>
#include <fstream>
#include <cstdlib>

// COMMAND ARGUMENT: 2.txt

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cerr << "\aNo command line parameters were provided. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		std::cerr << "\aToo many command line parameters found. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::ofstream fout;
	std::cout << "Opening file '" << argv[1] << "'... ";
	fout.open(argv[1]);

	if (!fout.is_open())
	{
		std::cerr << "\aCould not open file. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::cout << "Done." << std::endl;

	std::cout << "\nEnter anything to be written to '" << argv[1] << "' (CTRL-Z + Enter on a new line to quit):" << std::endl;

	char ch;
	while (std::cin.get(ch))
	{
		fout << ch;
	}

	fout.close();

	return 0;
}