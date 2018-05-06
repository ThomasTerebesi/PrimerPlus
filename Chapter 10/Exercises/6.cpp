// compile with move.h and move.cpp

#include <iostream>
#include "move.h"

int main()
{
	std::cout << "move0:" << std::endl;
	Move move0;
	move0.showmove();

	std::cout << "\nmove1:" << std::endl;
	Move move1(1.7,2.2);
	move1.showmove();

	std::cout << "\nmove2:" << std::endl;
	Move move2(3.5, 8.4);
	move2.showmove();

	std::cout << "\nStoring the sum of move1 and move2 in move3." << std::endl;
	std::cout << "move3:" << std::endl;
	Move move3(move1.add(move2));
	move3.showmove();

	std::cout << "\nResetting move2 to default values." << std::endl;
	move2.reset();
	std::cout << "move2:" << std::endl;
	move2.showmove();

	std::cout << "\nSetting new values for move2." << std::endl;
	move2.reset(13.1, 9.6);
	std::cout << "move2:" << std::endl;
	move2.showmove();

	std::cout << "\nStoring the sum of move1 and move2 in move0." << std::endl;
	move0 = move2.add(move1);
	std::cout << "move0:" << std::endl;
	move0.showmove();

	std::cin.get();

	return 0;
}