#include <iostream>

struct CandyBar
{
	const char* mBrandName;
	float mWeight;
	unsigned short mCalories;
};

int main()
{
	CandyBar snack = { "Mocha Munch", 2.3f, 350 };

	std::cout << "One piece of " << snack.mBrandName << " has a weight of " << snack.mWeight;
	std::cout << " and " << snack.mCalories << " calories." << std::endl;

	std::cin.get();
	return 0;
}