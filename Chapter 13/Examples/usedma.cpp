// compile with dma.h and dma.cpp

#include <iostream>
#include "dma.h"

int main()
{
	BaseDMA shirt("Portabelly", 8);
	LacksDMA balloon("red", "Blimpo", 4);
	HasDMA map("Mercator", "Buffalo Keys", 5);

	std::cout << "Displaying BaseDMA object:" << std::endl;
	std::cout << shirt << std::endl;

	std::cout << "Displaying LacksDMA object:" << std::endl;
	std::cout << balloon << std::endl;

	std::cout << "Displaying HasDMA object:" << std::endl;
	std::cout << map << std::endl;

	LacksDMA balloon2(balloon);
	std::cout << "Result of LacksDMA copy:" << std::endl;
	std::cout << balloon2 << std::endl;

	HasDMA map2;
	map2 = map;
	std::cout << "Result of HasDMA assignment:" << std::endl;
	std::cout << map2 << std::endl;

	std::cin.get();

	return 0;
}