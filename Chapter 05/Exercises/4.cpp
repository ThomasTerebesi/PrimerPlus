#include <iostream>

const float SIMPLE_INTEREST = 0.10f;
const float COMPOUND_INTEREST = 0.05f;
const float ORIGINAL_BALANCE = 100.0f;

int main()
{
	float daphneBalance = ORIGINAL_BALANCE;
	float cleoBalance = ORIGINAL_BALANCE;
	int year;

	std::cout << "\t\tD:\tC:" << std::endl;
	for (year = 1; cleoBalance <= daphneBalance; year++)
	{
		daphneBalance += ORIGINAL_BALANCE * SIMPLE_INTEREST;
		cleoBalance *= (1 + COMPOUND_INTEREST);

		std::cout << "Year " << year << ": \t" << daphneBalance << "\t" << cleoBalance << std::endl;
	}

	std::cout << "\nIt took " << (year - 1) << " years for the value of Cleo's investment to exceed the value of Daphne's investment." << std::endl;
	std::cout << "Daphne's balance at the start of year " << year << " is at " << daphneBalance << "." << std::endl;
	std::cout << "Cleo's balance at the start of year " << year << " is at " << cleoBalance << "." << std::endl;

	std::cin.get();

	return 0;
}