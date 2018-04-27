#include <iostream>
#include <cstring>

const int STRING_LENGTH = 64;
const int ARRAY_SIZE = 10;

struct CandyBar
{
	char brand[STRING_LENGTH];
	float weight;
	unsigned short calories;
};

void SetCandyBar(CandyBar & bar, 
	const char * brand = "Millennium Munch", 
	const float & weight = 285.5, 
	const unsigned short & calories = 350);
void DisplayCandyBar(const CandyBar & bar);

int main()
{
	std::cout << "Enter information for up to " << ARRAY_SIZE << " candy bars in the following format ('q' to quit):" << std::endl;
	
	CandyBar * testBar = new CandyBar;
	SetCandyBar(*testBar);
	DisplayCandyBar(*testBar);
	delete testBar;
	
	CandyBar candyBars[ARRAY_SIZE];

	int i;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		char inputBrand[STRING_LENGTH];
		float inputWeight;
		unsigned short inputCalories;

		std::cout << "\nPlease enter the brand of candy bar #" << (i + 1) << ": ";
		std::cin >> inputBrand;

		if (inputBrand[0] == 'q')
		{
			std::cout << "\aInput terminated by user." << std::endl;
			break;
		}

		std::cout << "Please enter the weight of one piece of " << inputBrand << " in grams: ";
		std::cin >> inputWeight;

		std::cout << "Please enter the calories of one piece of " << inputBrand << ": ";
		std::cin >> inputCalories;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.get();
			std::cout << "\aInput terminated by user." << std::endl;
			break;
		}

		SetCandyBar(candyBars[i], inputBrand, inputWeight, inputCalories);
	}

	switch (i)
	{
	case 0:
		std::cout << "\nNo candy bars were entered." << std::endl;
		break;
	case 1:
		std::cout << "\nHere is the candy bar you entered:" << std::endl;
		DisplayCandyBar(candyBars[0]);
		break;
	default: 
		std::cout << "\nHere are the candy bars you entered:" << std::endl;

		for (int j = 0; j < i; j++)
		{
			DisplayCandyBar(candyBars[j]);
		}
		
		break;
	}

	std::cin.get();
	std::cin.get();

	return 0;
}

void SetCandyBar(CandyBar & bar, const char * brand, const float & weight, const unsigned short & calories)
{
	strcpy_s(bar.brand, brand);
	bar.weight = weight;
	bar.calories = calories;
}

void DisplayCandyBar(const CandyBar & bar)
{
	std::cout << "\nBrand: " << bar.brand << std::endl;
	std::cout << "Weight: " << bar.weight << "g" << std::endl;
	std::cout << "Calories: " << bar.calories << std::endl;
}
