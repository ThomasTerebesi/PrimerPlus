// compile with 1vect.h and 1vect.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "1vect.h"

const unsigned short SIZE = 64;

void PrintResult(std::ostream & os, const unsigned long & stepsParam, VECTOR::Vector & resultParam);

int main()
{
	srand(time(0));	// seed random-number generator
	double direction;
	VECTOR::Vector step;
	VECTOR::Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dStep;

	char filename[SIZE];
	std::ofstream outFile;

	std::cout << "Enter the name of a text file: ";
	std::cin.getline(filename, SIZE);


	outFile.open(filename);
	if (!outFile.is_open())
	{
		std::cout << "Could not open the file " << filename << std::endl;
		std::cout << "Program terminating." << std::endl;

		std::cin.get();

		exit(EXIT_FAILURE);
	}

	std::cout << "Enter target distance (q to quit): ";
	while (std::cin >> target)
	{
		std::cout << "Enter step length: ";
		if (!(std::cin >> dStep))
			break;

		outFile << "Target distance: " << target << ", step size: " << dStep << std::endl;
		outFile << steps << ": " << result << std::endl;

		while (result.MagVal() < target)
		{
			direction = rand() % 360;
			step.Reset(dStep, direction, VECTOR::Vector::POL);
			result = result + step;
			outFile << (steps + 1) << ": " << result << std::endl;
			steps++;
		}

		PrintResult(std::cout, steps, result);
		std::cout << "More detailed information can be found in " << filename << "." << std::endl;

		PrintResult(outFile, steps, result);
		outFile << "\n\n";

		steps = 0;
		result.Reset(0.0, 0.0);

		std::cout << "\nEnter target distance (q to quit): ";
	}

	outFile.close();

	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;

	return 0;
}

void PrintResult(std::ostream & os, const unsigned long & stepsParam, VECTOR::Vector & resultParam)
{
	os << "\nAfter " << stepsParam << " steps, the subject has the following location:" << std::endl;
	os << resultParam << std::endl;
	resultParam.PolarMode();
	os << "\t\tor" << std::endl;
	os << resultParam << std::endl;
	os << "Average outward distance per step = " << resultParam.MagVal() / stepsParam << std::endl;
	
	resultParam.RectMode(); // reset to RECT
}
