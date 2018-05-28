#include "1winec.h"

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
	: label(l), years(y)
{
	vintagesAndBottles.first.resize(years);
	vintagesAndBottles.second.resize(years);

	for (int i = 0; i < years; i++)
	{
		vintagesAndBottles.first[i] = yr[i];
		vintagesAndBottles.second[i] = bot[i];
	}
}

Wine::Wine(const char * l, int y)
	: label(l), years(y)
{
	vintagesAndBottles.first.resize(years);
	vintagesAndBottles.second.resize(years);
}

void Wine::GetBottles()
{
	std::cout << "Enter " << label << " data for " << years << " year(s):" << std::endl;

	for (int i = 0; i < years; i++)
	{
		std::cout << "Enter the year: ";
		std::cin >> vintagesAndBottles.first[i];
		ClearInput("Please enter a valid year: ", vintagesAndBottles.first[i]);


		std::cout << "Enter the number of bottles for that year: ";
		std::cin >> vintagesAndBottles.second[i];
		ClearInput("Please enter a valid number of bottles: ", vintagesAndBottles.second[i]);
	}
}

int Wine::Sum() const
{
	int sum = 0;

	for (int i = 0; i < years; i++)
	{
		sum += vintagesAndBottles.second[i];
	}

	return sum;
}

void Wine::Show() const
{
	std::cout << "Wine: " << label << std::endl;
	std::cout << "\tYear\tBottles" << std::endl;

	for (int i = 0; i < years; i++)
	{
		std::cout << "\t" << vintagesAndBottles.first[i] << "\t" << vintagesAndBottles.second[i] << std::endl;
	}
}

