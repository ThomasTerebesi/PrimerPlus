// compile with sales.h and sales.cpp

#include <iostream>
#include "sales.h"

int main()
{
	double yearOneSales[4] = { 156.0, 394.0, 28.0, 77.0 };
	// double yearOneSales[3] = { 156.0, 394.0, 28.0 };

	SALES::Sales yearOne(yearOneSales, 4);

	std::cout << "Sales data of year one:" << std::endl;
	yearOne.ShowSales();

	std::cout << "\nPlease enter the sales data of year two:" << std::endl;
	SALES::Sales yearTwo;

	std::cout << "\nSales data of year two:" << std::endl;
	yearTwo.ShowSales();

	std::cin.get();

	return 0;
}