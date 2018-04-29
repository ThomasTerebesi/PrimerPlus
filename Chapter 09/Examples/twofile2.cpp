// to be compiled with twofile1.cpp
#include <iostream>

extern int tom; // tom defined elsewhere
static int dick = 10; // overrides external dick
int harry = 200; // external variable definition; no conflict with harry in twofile1.cpp

void RemoteAccess()
{
	std::cout << "RemoteAccess() reports the following addresses:" << std::endl;
	std::cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry" << std::endl;
}
