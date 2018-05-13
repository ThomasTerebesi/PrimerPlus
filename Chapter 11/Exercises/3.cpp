// compile with 3vect.h and 3vect.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "3vect.h"

int main()
{
	srand(time(0));	// seed random-number generator
	double direction;
	VECTOR::Vector step;
	VECTOR::Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dStep;
	
	unsigned short trialsInput;
	unsigned long highest, lowest;
	unsigned long long sumSteps = 0;

	std::cout << "Enter the number of trials (up to " << USHRT_MAX << ") you want to execute (q to quit): ";
	while (std::cin >> trialsInput)
	{
		std::cout << "Enter target distance: ";
		if (!(std::cin >> target))
			break;

		std::cout << "Enter step length: ";
		if (!(std::cin >> dStep))
			break;

		for (int i = 0; i < trialsInput; i++)
		{
			while (result.MagVal() < target)
			{
				direction = rand() % 360;
				step.Reset(dStep, direction, VECTOR::Vector::POL);
				result = result + step;
				steps++;
			}

			if (i == 0)
				highest = lowest = steps;
			else if (steps > highest)
				highest = steps;
			else if (steps < lowest)
				lowest = steps;

			sumSteps += steps;

			steps = 0;
			result.Reset(0.0, 0.0);
		}

		std::cout << "Results after " << trialsInput << " trials:" << std::endl;
		std::cout << "Highest number of steps: " << highest << std::endl;
		std::cout << " Lowest number of steps: " << lowest << std::endl;
		std::cout << "Average number of steps: " << (sumSteps / trialsInput) << std::endl;

		std::cout << "\n\nEnter the number of trials (up to " << USHRT_MAX << ") you want to execute (q to quit): ";
	}

	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;

	std::cin.get();

	return 0;
}