// compile with queue.h and queue.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "5queue.h"

const int MIN_PER_HR = 60;

bool newCustomer(double x); // is there a new customer?
void runSimulation(bool output = false);

int main()
{
	srand(static_cast<int>(time(0)));

	std::cout << "Bank of Heather Automatic Teller Simulation" << std::endl;
	std::cout << "\nObjective: Find the maximum number of customers per" << std::endl;
	std::cout << "hour with an average wait time of exactly one minute." << std::endl;
	std::cout << "Two ATMs are used for the simulation(s)." << std::endl;

	std::cout << "\nWARNING: This simulation may take a long time to run." << std::endl;

	std::cout << "\n\nDo you want to run the simulation (y/n)? ";
	char ch;
	std::cin >> ch;
	while (ch == 'y' || ch == 'Y')
	{
		runSimulation(true);

		std::cout << "\n\nDo you want to run the simulation again (y/n)? ";
		std::cin >> ch;
	}

	return 0;
}

bool newCustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);
}

void runSimulation(bool output)
{
	unsigned short hours = 100;

	// simulation will run 1 cycle per minute
	long cycleLimit = MIN_PER_HR * hours;	// # of cycles

	double perHour;		// average # of arrival per hour
	double minPerCust;	// average time between arrivals

	long turnaways = 0;
	long customers = 0; // joined the queue
	long served = 0;	// served during the simulation
	long sumLine = 0;	// cumulative line length
	long lineWait = 0;	// cumulative time in line

	int waitTimeOne = 0;	// time until autoteller is free
	int waitTimeTwo = 0;

	unsigned long runsExecuted = 0; // holds the number of runs executed so far

	do
	{
		perHour = rand() % 120;
		minPerCust = static_cast<double>(MIN_PER_HR) / perHour;

		Queue lineOne(static_cast<int>(hours * perHour));
		Queue lineTwo(static_cast<int>(hours * perHour));

		Item temp;	// new customer data
		turnaways = 0;
		customers = 0;
		served = 0;
		sumLine = 0;
		waitTimeOne = 0;
		waitTimeTwo = 0;
		lineWait = 0;

		// running the simulation
		for (int cycle = 0; cycle < cycleLimit; cycle++)
		{
			if (newCustomer(minPerCust))
			{
				if (lineOne.isFull() && lineTwo.isFull())
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle);
					if (lineOne.queueCount() >= lineTwo.queueCount())
						lineTwo.enqueue(temp);
					else
						lineOne.enqueue(temp);
				}
			}


			if (waitTimeOne <= 0 && !lineOne.isEmpty())
			{
				lineOne.dequeue(temp);
				waitTimeOne = temp.ptime();
				lineWait += cycle - temp.when();
				served++;
			}

			if (waitTimeOne > 0)
				waitTimeOne--;

			sumLine+= lineOne.queueCount();


			if (waitTimeTwo <= 0 && !lineTwo.isEmpty())
			{
				lineTwo.dequeue(temp);
				waitTimeTwo = temp.ptime();
				lineWait += cycle - temp.when();
				served++;
			}

			if (waitTimeTwo > 0)
				waitTimeTwo--;
			sumLine += lineTwo.queueCount();
		}

		runsExecuted++;

		// show the user that something is happening
		if (output)
		{
			if (runsExecuted % 100 == 0)
				std::cout << ".";
			if (runsExecuted % 5000 == 0)
				std::cout << "\n";
		}
	} while (static_cast<double>(lineWait) / served != 1.0);

	if (output)
	{
		std::cout << std::endl;
		std::cout << "\n\aSUCCESS!" << std::endl;
		std::cout << "\t   simulation runs: " << runsExecuted << std::endl;
		std::cout << "\tcustomers accepted: " << customers << std::endl;
		std::cout << "\t  customers served: " << served << std::endl;
		std::cout << "\taverage queue size: ";
		std::cout.precision(2);
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::cout << static_cast<double>(sumLine) / cycleLimit << std::endl;
		std::cout << "\t average wait time: " << static_cast<double>(lineWait) / served << " minutes" << std::endl;

		std::cout << "\nFor this simulation run, " << static_cast<float>(customers) / hours << " customers per hour lead" << std::endl;
		std::cout << "to an average wait time of exactly one minute." << std::endl;
	}
}
