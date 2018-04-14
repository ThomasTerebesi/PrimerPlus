#include <iostream>
#include <fstream>

int main()
{
	char automobile[50];
	int year;
	double aPrice;
	double dPrice;

	std::ofstream outFile;			// create object for output
	outFile.open("carinfo.txt");	// associate with a file

	std::cout << "Enter the make and model of the automobile: ";
	std::cin.getline(automobile, 50);
	std::cout << "Enter the model year: ";
	std::cin >> year;
	std::cout << "Enter the original asking price: ";
	std::cin >> aPrice;

	dPrice = 0.913 * aPrice;

	// display info on screen
	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout.setf(std::ios_base::showpoint);
	std::cout << "Make and model: " << automobile << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << "Was asking $" << aPrice << std::endl;
	std::cout << "Now asking $" << dPrice << std::endl;

	// save info to file basically doing the same things with outFile instead of cout
	outFile << std::fixed;
	outFile.precision(2);
	outFile.setf(std::ios_base::showpoint);
	outFile << "Make and model: " << automobile << std::endl;
	outFile << "Year: " << year << std::endl;
	outFile << "Was asking $" << aPrice << std::endl;
	outFile << "Now asking $" << dPrice << std::endl;

	outFile.close();	// close the connection

	std::cin.get();
	std::cin.get();
	return 0;
}