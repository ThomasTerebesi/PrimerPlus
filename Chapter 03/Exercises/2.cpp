#include <iostream>

int main()
{
	const int FOOT_IN_INCHES = 12;
	const float INCH_IN_METERS = 0.0254f;
	const float KILOGRAM_IN_POUNDS = 2.2f;

	std::cout << "I will calculate your body mass index (BMI)." << std::endl;
	std::cout << "Please enter your weight in pounds: ";
	int weight = 0;
	std::cin >> weight;
	std::cout << "Please enter the first component of your height in feet: ";
	int feet = 0;
	std::cin >> feet;
	std::cout << "Please enter the second component of your height in inches: ";
	int inches = 0;
	std::cin >> inches;

	float heightInMeters = (inches + (feet * FOOT_IN_INCHES)) * INCH_IN_METERS;
	float weightInKilograms = weight / KILOGRAM_IN_POUNDS;

	std::cout << "Your height in meters: " << heightInMeters << std::endl;
	std::cout << "Your weight in kilograms: " << weightInKilograms << std::endl;

	int bodyMassIndex = static_cast<int>(weightInKilograms/(heightInMeters*heightInMeters));

	std::cout << "Your BMI: " << bodyMassIndex << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}