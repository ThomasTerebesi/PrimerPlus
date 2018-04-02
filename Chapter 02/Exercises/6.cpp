#include <iostream>

double LightyearsToAstronomicalUnits(double lightYears);

int main()
{
	std::cout << "Enter a number of light years and I will convert that value into astronomical units: " << std::endl;
	double inputLightYears = 0;
	std::cin >> inputLightYears;
	std::cout << inputLightYears << " light years equals " << LightyearsToAstronomicalUnits(inputLightYears) << " astronomical units." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}

double LightyearsToAstronomicalUnits(double lightYears)
{
	return lightYears * 63240.0f;
}