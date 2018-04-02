#include <iostream>

float CelsiusToFahrenheit(float C);

int main()
{
	std::cout << "Enter a temperature in Celsius and I will convert it to the equivalent Fahrenheit value: " << std::endl;
	float celsiusInput = 0;
	std::cin >> celsiusInput;
	std::cout << celsiusInput << " degrees Celsius equals " << CelsiusToFahrenheit(celsiusInput) << " degrees Fahrenheit." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}

float CelsiusToFahrenheit(float C)
{
	return 1.8f * C + 32.0f;
}