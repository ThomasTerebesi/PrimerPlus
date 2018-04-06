#include <iostream>

struct CandyBar
{
	const char* mBrandName;
	float mWeight;
	unsigned short mCalories;
};

int main()
{
	CandyBar bars[3];
	bars[0] = { "Snickers", 50.0f, 242 };
	bars[1] = { "Mars", 51.0f, 229 };
	bars[2] = { "Duplo", 18.2f, 101 };

	std::cout << bars[0].mBrandName << " has a weight of ";
	std::cout << bars[0].mWeight << " grams and contains ";
	std::cout << bars[0].mCalories << " calories." << std::endl;	
	
	std::cout << bars[1].mBrandName << " has a weight of ";
	std::cout << bars[1].mWeight << " grams and contains ";
	std::cout << bars[1].mCalories << " calories." << std::endl;

	std::cout << bars[2].mBrandName << " has a weight of ";
	std::cout << bars[2].mWeight << " grams and contains ";
	std::cout << bars[2].mCalories << " calories." << std::endl;

	std::cin.get();
	return 0;
}