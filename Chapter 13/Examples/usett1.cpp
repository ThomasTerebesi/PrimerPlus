// compile with tabtenn1.h and tabtenn1.cpp

#include <iostream>
#include "tabtenn1.h"

int main(void)
{
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);

	rplayer1.Name();
	if (rplayer1.HasTable())
		std::cout << ": has a table." << std::endl;
	else 
		std::cout << ": has no table." << std::endl;

	player1.Name();
	if (player1.HasTable())
		std::cout << ": has a table." << std::endl;
	else
		std::cout << ": has no table." << std::endl;

	rplayer1.Name();
	std::cout << "; Rating: " << rplayer1.Rating() << std::endl;

	// initialize RatedPlayer using TableTennisPlayer object
	RatedPlayer rplayer2(1212, player1);

	rplayer2.Name();
	std::cout << "; Rating: " << rplayer2.Rating() << std::endl;

	std::cin.get();

	return 0;
}