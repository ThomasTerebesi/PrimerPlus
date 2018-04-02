#include <iostream>

void PrintHoursAndMinutes(int h, int m);

int main()
{
	std::cout << "Enter the number of hours: ";
	int hours = 0;
	std::cin >> hours;

	std::cout << "Enter the number of minutes: ";
	int minutes = 0;
	std::cin >> minutes;

	PrintHoursAndMinutes(hours, minutes);

	std::cin.get();
	std::cin.get();
	return 0;
}

void PrintHoursAndMinutes(int h, int m)
{
	std::cout << "Time: " << h << ":" << m << std::endl;
}