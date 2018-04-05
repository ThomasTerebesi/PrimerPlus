#include <iostream>

int main()
{
	int nights = 1001;
	int* pt = new int;
	*pt = 1001;

	std::cout << "nights value = " << nights << ": location = " << &nights << std::endl;
	std::cout << "int value = " << *pt << ": location = " << pt << std::endl;

	double* pd = new double;
	*pd = 10000001.0;

	std::cout << "double value = " << *pd << ": location = " << pd << std::endl;
	std::cout << "location of pointer pd: " << &pd << std::endl;
	std::cout << "size of pt = " << sizeof(pt) << ": size of *pt = " << sizeof(*pt) << std::endl;
	std::cout << "size of pd = " << sizeof(pd) << ": size of *pd = " << sizeof(*pd) << std::endl;

	delete pt;
	delete pd;

	std::cin.get();
	return 0;
}