#include <iostream>
#include <string>

struct Car
{
	std::string mMake;
	int mBuildYear;
};

int main()
{
	std::cout << "How many cars do you wish to catalog? ";
	unsigned short numCars;
	std::cin >> numCars;

	Car* carArray = new Car[numCars];
	
	for (int i = 0; i < numCars; i++)
	{
		std::cin.get();
		std::cout << "\nCar #" << (i + 1) << ":" << std::endl;
		
		std::cout << "Please enter the make: ";
		getline(std::cin, carArray[i].mMake);

		std::cout << "Please enter the build year: ";
		std::cin >> carArray[i].mBuildYear;
	}

	std::cout << "\nHere is your collection:" << std::endl;
	for (int i = 0; i < numCars; i++)
		std::cout << carArray[i].mBuildYear << "\t" << carArray[i].mMake << std::endl;

	std::cin.get();
	std::cin.get();

	delete[] carArray;
	return 0;
}