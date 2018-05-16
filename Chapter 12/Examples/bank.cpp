// compile with queue.h and queue.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newCustomer(double x); // is there a new customer?

int main()
{
	srand(static_cast<int>(time(0)));

	std::cout << "Case Study: Bank of Heather Automatic Teller" << std::endl;
	std::cout << "Enter maximum size of queue: ";
	int qs;
	std::cin >> qs;
	Queue line(qs);	// line holds up to qs people

	std::cout << "Enter the number of simulation hours: ";
	int hours;
	std::cin >> hours;

	// simulation will run 1 cycle per minute
	long cycleLimit = MIN_PER_HR * hours;	// # of cycles

	std::cout << "Enter the average number of customers per hour: ";
	double perHour; // average # of arrival per hour
	std::cin >> perHour;
	double minPerCust = MIN_PER_HR / perHour; // average time between arrivals

	Item temp;			// new customer data
	long turnaways = 0;	// turned away by full queue
	long customers = 0; // joined the queue
	long served = 0;	// served during the simulation
	long sumLine = 0;	// cumulative line length
	int waitTime = 0;	// time until autoteller is free
	long lineWait = 0;	// cumulative time in line

	// running the simulation
	for (int cycle = 0; cycle < cycleLimit; cycle++)
	{
		if (newCustomer(minPerCust))	// new customer
		{
			if (line.isFull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);		// cycle = time of arrival
				line.enqueue(temp);		// add new customer to line
			}
		}

		if (waitTime <= 0 && !line.isEmpty())
		{
			line.dequeue(temp);			// attend next customer
			waitTime = temp.ptime();	// for waitTime minutes
			lineWait += cycle - temp.when();
			served++;
		}

		if (waitTime > 0)
			waitTime--;

		sumLine += line.queueCount();
	}

	// reporting results
	if (customers > 0)
	{
		std::cout << "\ncustomers accepted: " << customers << std::endl;
		std::cout << "  customers served: " << served << std::endl;
		std::cout << "         turnaways: " << turnaways << std::endl;
		std::cout << "average queue size: ";
		std::cout.precision(2);
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::cout << static_cast<double>(sumLine) / cycleLimit << std::endl;
		std::cout << " average wait time: " << static_cast<double>(lineWait) / served << " minutes" << std::endl;
	}
	else
		std::cout << "No customers!" << std::endl;

	std::cout << "\nDone!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}

bool newCustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);
}
