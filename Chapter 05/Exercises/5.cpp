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

	std::cout << "Enter the number of copies of 'C++ for Fools' sold.\n\n";

	int* salesPerMonth = new int[12];
	int* totalSales = new int;
	*totalSales = 0;

	for (int i = 0; i < 12; i++)
	{
		std::cout << "Copies sold in " << months[i] << ": ";
		std::cin >> salesPerMonth[i];
		*totalSales += salesPerMonth[i];
	}

	std::cout << "\n'C++ for Fools' sold " << *totalSales << " copies." << std::endl;

	std::cin.get();
	std::cin.get();

	delete[] salesPerMonth;
	delete totalSales;
	
	return 0;
}