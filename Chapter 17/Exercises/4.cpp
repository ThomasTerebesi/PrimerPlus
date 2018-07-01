#include <iostream>
#include <fstream>
#include <cstdlib>

// NO COMMAND ARGUMENTS

int main()
{
	// open the first source file
	std::ifstream fin1;
	std::cout << "Opening source file '4_src1.txt'... ";
	fin1.open("4_src1.txt");

	if (!fin1.is_open())
	{
		std::cerr << "\n\aCould not open file. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::cout << "Done." << std::endl;

	// open the second source file
	std::ifstream fin2;
	std::cout << "Opening source file '4_src2.txt'... ";
	fin2.open("4_src2.txt");

	if (!fin2.is_open())
	{
		std::cerr << "\n\aCould not open file. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::cout << "Done." << std::endl;

	// open the destination file
	std::ofstream fout;
	std::cout << "\nOpening destination file '4_dest.txt'... ";
	fout.open("4_dest.txt");

	if (!fout.is_open())
	{
		std::cerr << "\n\aCould not open file. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::cout << "Done." << std::endl;

	// concatenate contents from the source files and write the results to the destination files
	char ch;

	while (!fin1.eof() && !fin2.eof())
	{
		while (fin1.get(ch) && ch != '\n')
			fout << ch;
		fout << ' ';

		while (fin2.get(ch) && ch != '\n')
			fout << ch;
		fout << ' ';

		fout << std::endl;
	}

	
	while (!fin1.eof() && fin2.eof())	// first file is longer than the second	
	{
		while (fin1.get(ch) && ch != '\n')
			fout << ch;

		fout << std::endl;
	}

	while (fin1.eof() && !fin2.eof())	// second file is longer than the first
	{
		while (fin2.get(ch) && ch != '\n')
			fout << ch;

		fout << std::endl;
	}

	// cleanup and exit
	fin1.close();
	fin2.close();
	fout.close();

	std::cout << "Operation successful.";

	std::cin.get();

	return 0;
}