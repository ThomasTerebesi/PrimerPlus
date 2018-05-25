// compile with workermi.h and workermi.cpp

#include <iostream>
#include <cstring>
#include "workermi.h"

const int SIZE = 5;

int main()
{
	Worker * lolas[SIZE];

	int ct;

	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;

		std::cout << "Enter the employee category:" << std::endl;
		std::cout << "w: Waiter\ts: Singer" << std::endl;
		std::cout << "t: Singing Waiter\tq : Quit" << std::endl;
		
		std::cin >> choice;

		while (strchr("wstq", choice) == NULL)
		{
			std::cout << "Please enter a w, s, t, or q: ";
			std::cin >> choice;
		}

		if (choice == 'q')
			break;

		switch (choice)
		{
		case 'w':
			lolas[ct] = new Waiter;
			break;
		case 's':
			lolas[ct] = new Singer;
			break;
		case 't':
			lolas[ct] = new SingingWaiter;
			break;
		}

		std::cin.get();

		lolas[ct]->Set();

		std::cout << std::endl;
	}

	std::cout << "\nHere is your staff:" << std::endl;

	int i;

	for (i = 0; i < ct; i++)
	{
		std::cout << std::endl;
		lolas[i]->Show();
	}

	for (i = 0; i < ct; i++)
		delete lolas[i];

	std::cout << "\nBye." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}