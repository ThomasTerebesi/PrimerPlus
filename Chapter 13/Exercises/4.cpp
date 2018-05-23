// compile with 4port.h and 4port.cpp

#include <iostream>
#include "4port.h"

int main()
{
	std::cout << "Example program for the Port and VintagePort classes." << std::endl;

	Port portOne("Ferreira", "Tawny", 12);

	std::cout << portOne;
	std::cout << "\nDrinking 3 bottles of portOne's " << portOne.BottleCount() << " bottles.";
	portOne -= 3;
	portOne.Show();

	std::cout << "\nDrunkenly trying to drink 10 more bottles of portOne's " << portOne.BottleCount() << " bottles." << std::endl;
	portOne -= 10;
	std::cout << "\nThat didn't work. Trying to add -10 bottles to portOne's " << portOne.BottleCount() << " bottles." << std::endl;
	portOne += -10;

	std::cout << "\nCopying portOne into portTwo, then we will have more to drink.";
	Port portTwo(portOne);
	portTwo.Show();

	std::cout << "\nCreating new object portThree and showing its contents:";
	Port portThree("Sandeman", "Fine Tawny", 7);
	std::cout << portThree;
	
	std::cout << "\nAssigning portThree to portTwo and showing portTwo's contents:";
	portTwo = portThree;
	portTwo.Show();

	std::cout << "\nCreating vintageOne by assigning it a temporary vintage object.";
	VintagePort vintageOne = VintagePort("Delaforce", 4, "Delly", 2010);
	vintageOne.Show();

	std::cout << "\nCopying vintageOne into vintageTwo after adding 3 bottles to it.";
	vintageOne += 3;
	VintagePort vintageTwo (vintageOne);
	std::cout << vintageTwo;

	std::cout << "\nDrunkenly trying to drink 8 bottles of vintageTwo's " << vintageTwo.BottleCount() << " bottles." << std::endl;
	vintageTwo -= 8;

	std::cout << "\nCreating empty object vintageThree and displaying its contents:";
	VintagePort vintageThree;
	vintageThree.Show();

	std::cout << "\nDone." << std::endl;

	std::cin.get();

	return 0;
}