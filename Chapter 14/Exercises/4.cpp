// compile with 4person.h and 4person.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "4person.h"

const short SIZE = 4;

int main()
{
	srand(static_cast<int>(time(0)));
	Person * pp[SIZE];

	int ct;

	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;

		std::cout << "Enter the category:" << std::endl;
		std::cout << "g: Gunslinger\tp: Poker Player" << std::endl;
		std::cout << "b: Bad Dude\tn: Person" << std::endl;
		std::cout << "q: Quit" << std::endl;

		std::cin >> choice;

		while (strchr("gpbnq", choice) == NULL)
		{
			std::cout << "Please enter a g, p, b, or q: ";
			std::cin >> choice;
		}

		if (choice == 'q')
			break;

		switch (choice)
		{
		case 'g':
			pp[ct] = new Gunslinger;
			break;
		case 'p':
			pp[ct] = new PokerPlayer;
			break;
		case 'b':
			pp[ct] = new BadDude;
			break;
		case 'n':
			pp[ct] = new Person;
			break;
		}

		std::cin.get();

		pp[ct]->Set();

		std::cout << std::endl;
	}

	if (ct > 0)
	{
		std::cout << "\nBad guys:" << std::endl;

		int i;

		for (i = 0; i < ct; i++)
		{
			std::cout << std::endl;
			pp[i]->Show();
		}

		for (i = 0; i < ct; i++)
			delete pp[i];
	}
	else
		std::cout << "\nNothing was entered." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}