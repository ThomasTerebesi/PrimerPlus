#include "2winec.h"

void ClearInput(const std::string & msg, int & var)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << msg;
		std::cin >> var;
	}
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
	: std::string(l), PairArray(std::valarray<int>(y), std::valarray<int>(y)), years(y)
{
	for (int i = 0; i < years; i++)
	{
		PairArray::first[i] = yr[i];
		PairArray::second[i] = bot[i];
	}
}

Wine::Wine(const char * l, int y)
	: std::string(l), PairArray(std::valarray<int>(y), std::valarray<int>(y)), years(y)
{
}

void Wine::GetBottles()
{
	std::cout << "Enter " << Label() << " data for " << years << " year(s):" << std::endl;

	for (int i = 0; i < years; i++)
	{
		std::cout << "Enter the year: ";
		std::cin >> PairArray::first[i];
		ClearInput("Please enter a valid year: ", PairArray::first[i]);


		std::cout << "Enter the number of bottles for that year: ";
		std::cin >> PairArray::second[i];
		ClearInput("Please enter a valid number of bottles: ", PairArray::second[i]);
	}
}

int Wine::Sum() const
{
	int sum = 0;

	for (int i = 0; i < years; i++)
	{
		sum += PairArray::second[i];
	}

	return sum;
}

void Wine::Show() const
{
	std::cout << "Wine: " << Label() << std::endl;
	std::cout << "\tYear\tBottles" << std::endl;

	for (int i = 0; i < years; i++)
	{
		std::cout << "\t" << PairArray::first[i] << "\t" << PairArray::second[i] << std::endl;
	}
}

