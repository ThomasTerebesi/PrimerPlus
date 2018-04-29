// to be compiled with twofile2.cpp
#include <iostream>

int tom = 3; // external variable definition
int dick = 30; // external variable definition
static int harry = 300; // static, internal linkage

void RemoteAccess();

int main()
{
	std::cout << "main() reports the following addresses:" << std::endl;
	std::cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry" << std::endl;

	RemoteAccess();

	std::cin.get();

	return 0;
}