#include <iostream>
#include "sales.h"

int main()
{
	SALES::Sales yearOne, yearTwo;

	// double yearOneSales[4] = { 156.0, 394.0, 28.0, 77.0 };
	double yearOneSales[3] = { 156.0, 394.0, 28.0 };

	setSales(yearOne, yearOneSales, 3);

	std::cout << "Sales data of year one:" << std::endl;
	showSales(yearOne);

	std::cout << "\nPlease enter the sales data of year two:" << std::endl;
	setSales(yearTwo);

	std::cout << "\nSales data of year two:" << std::endl;
	showSales(yearTwo);

	std::cin.get();

	return 0;
}