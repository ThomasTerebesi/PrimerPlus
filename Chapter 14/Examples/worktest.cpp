// compile with worker0.h and worker0.cpp

#include <iostream>
#include "worker0.h"

const int LIMIT = 4;

int main()
{
	Waiter bob("Bob Apple", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);

	Waiter wTemp;
	Singer sTemp;

	Worker * pw[LIMIT] = { &bob, &bev, &wTemp, &sTemp };

	int i;

	for (i = 2; i < LIMIT; i++)
		pw[i]->Set();

	std::cout << std::endl;

	for (i = 0; i < LIMIT; i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}

	std::cin.get();

	return 0;
}