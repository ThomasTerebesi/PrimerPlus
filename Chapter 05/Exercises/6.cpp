#include <iostream>

int main()
{
	const char* months[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	int sales[3][12];
	int yearlySales[3];
	int totalSales = 0;

	for (int year = 0; year < 3; year++)
	{
		yearlySales[year] = 0;
		for (int month = 0; month < 12; month++)
		{
			std::cout << "Copies sold in " << months[month] << " of year " << (year + 1) << ": ";
			std::cin >> sales[year][month];
			yearlySales[year] += sales[year][month];
		}
		std::cout << "\n'C++ for Fools' sold " << yearlySales[year] << " copies in year " << (year + 1) << ".\n" << std::endl;
		totalSales += yearlySales[year];
	}

	std::cout << "\n'C++ for Fools' sold " << totalSales << " copies in total." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}