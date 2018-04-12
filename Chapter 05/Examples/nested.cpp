#include <iostream>

const int CITIES = 5;
const int YEARS = 4;

int main()
{
	const char* cities[CITIES] = {
		"Gribble City",
		"Gribbletown",
		"New Gribble",
		"San Gribble",
		"Gribble Vista"
	};

	int maxtemps[YEARS][CITIES] = {
		{ 96, 100, 87, 101, 105 },
		{ 96, 100, 91, 107, 104 },
		{ 97, 101, 93, 108, 107 },
		{ 98, 103, 95, 109, 108 }
	};

	std::cout << "Maximum temperatures for 2008 - 2011\n\n";
	for (int city = 0; city < CITIES; ++city)
	{
		std::cout << cities[city] << ":\t";
		for (int year = 0; year < YEARS; ++year)
			std::cout << maxtemps[year][city] << "\t";
		std::cout << std::endl;
	}

	std::cin.get();
	return 0;
}