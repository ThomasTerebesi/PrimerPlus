// compile with tabtenn0.h and tabtenn0.cpp

#include <iostream>
#include "tabtenn0.h"

int main(void)
{
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);

	player1.Name();
	if (player1.HasTable())
		std::cout << ": has a table." << std::endl;
	else 
		std::cout << ": has no table." << std::endl;

	player2.Name();
	if (player2.HasTable())
		std::cout << ": has a table." << std::endl;
	else
		std::cout << ": has no table." << std::endl;

	std::cin.get();

	return 0;
}