#include <iostream>
#include <array>
#include <string>

const unsigned short SEASONS = 4;
const std::array<std::string, SEASONS> SEASON_NAMES = { "Spring", "Summer", "Fall", "Winter" };

// function to modify an array object
void Fill(std::array<double, SEASONS>* pa);

// function that uses an array object without modifying it
void Show(std::array<double, SEASONS> da);

int main()
{
	std::array<double, SEASONS> expenses;
	Fill(&expenses);
	Show(expenses);

	std::cin.get();
	std::cin.get();

	return 0;
}

void Fill(std::array<double, SEASONS>* pa)
{
	for (int i = 0; i < SEASONS; i++)
	{
		std::cout << "Enter " << SEASON_NAMES[i] << " expenses: $";
		std::cin >> (*pa)[i];
	}
}

void Show(std::array<double, SEASONS> da)
{
	double total = 0.0;

	std::cout << "\nEXPENSES\n";

	for (int i = 0; i < SEASONS; i++)
	{
		std::cout << SEASON_NAMES[i] << ": $" << da[i] << std::endl;
		total += da[i];
	}

	std::cout << "Total Expenses: $" << total << std::endl;
}
