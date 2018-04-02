#include <iostream>

void PrintMice();
void PrintRun();

int main()
{
	PrintMice();
	PrintMice();
	PrintRun();
	PrintRun();

	std::cin.get();
	return 0;
}

void PrintMice()
{
	std::cout << "Three blind mice" << std::endl;
}

void PrintRun()
{
	std::cout << "See how they run" << std::endl;
}