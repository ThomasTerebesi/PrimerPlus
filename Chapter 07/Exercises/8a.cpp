#include <iostream>
#include <string>

const unsigned short SEASONS = 4;
const char* SEASON_NAMES[SEASONS] = { "Spring", "Summer", "Fall", "Winter" };

void Fill(double arr[], int n);
void Show(double arr[], int n);

int main()
{
	double expenses[SEASONS];
	Fill(expenses, SEASONS);
	Show(expenses, SEASONS);

	std::cin.get();
	std::cin.get();

	return 0;
}

void Fill(double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter " << SEASON_NAMES[i] << " expenses: $";
		std::cin >> arr[i];
	}
}

void Show(double arr[], int n)
{
	double total = 0.0;

	std::cout << "\nEXPENSES\n";

	for (int i = 0; i < n; i++)
	{
		std::cout << SEASON_NAMES[i] << ": $" << arr[i] << std::endl;
		total += arr[i];
	}

	std::cout << "Total Expenses: $" << total << std::endl;
}
