#include <iostream>

int main()
{
	const float ONE_HUNDRED_KM_IN_M = 62.14;
	const float GALLON_IN_LITERS = 3.875;

	std::cout << "How many liters of gasoline did you use per 100 kilometers? ";
	float europeanUsage;
	std::cin >> europeanUsage;

	float usageInGallons = europeanUsage / GALLON_IN_LITERS;
	std::cout << "You used " << usageInGallons << " per 62.14 miles." << std::endl;

	int result = ONE_HUNDRED_KM_IN_M / usageInGallons;
	std::cout << "Therefore, you used " << result << " miles per gallon." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}