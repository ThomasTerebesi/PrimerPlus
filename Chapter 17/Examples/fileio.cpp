#include <iostream>	// not needed for many systems
#include <fstream>
#include <string>

int main()
{
	std::string filename;

	std::cout << "Enter name for new file: ";
	std::cin >> filename;

	// create output stream object for new file and call it fout
	std::ofstream fout(filename.c_str());

	fout << "For your eyes only!" << std::endl;		// write to file
	std::cout << "Enter your secret number: ";		// write to screen
	
	float secret;
	std::cin >> secret;
	
	fout << "Your secret number is " << secret << "." << std::endl;
	fout.close();									// close file

	// create input stream object for new file and call it fin
	std::ifstream fin(filename.c_str());
	std::cout << "\nHere are the contents of " << filename << ":" << std::endl;
	
	char ch;
	while (fin.get(ch))								// read character from file and
		std::cout << ch;							// write it to the screen
	
	std::cout << "\nDone." << std::endl;

	fin.close();

	std::cin.get();
	std::cin.get();

	return 0;
}