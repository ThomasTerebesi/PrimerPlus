#include <iostream>

int main()
{
	std::cout << "Enter the world's population: ";
	unsigned long long worldPopulation;
	std::cin >> worldPopulation;

	std::cout << "Enter the population of your home country: ";
	unsigned long long countryPopulation;
	std::cin >> countryPopulation;

	float percentage = (static_cast<float>(countryPopulation) / worldPopulation) * 100.0f;

	std::cout << "The population of your chosen country is " << percentage << "% of the world population." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}