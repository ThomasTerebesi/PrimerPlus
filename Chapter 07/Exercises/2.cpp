#include <iostream>

const unsigned short ARRAY_SIZE = 10;

unsigned short ArrayInput(unsigned short ar[]);
void DisplayArray(unsigned short ar[], unsigned short n);
float ArrayAverage(unsigned short ar[], unsigned short n);

int main()
{
	unsigned short golfScores[10];

	std::cout << "Enter up to 10 golf scores ('q' to quit).\n" << std::endl;
	unsigned short counter = ArrayInput(golfScores);

	switch (counter)
	{
	case 0:
		std::cout << "\nYou did not enter any scores." << std::endl;
		break;
	case 1:
		std::cout << "\nYou only entered one score: " << golfScores[0] << std::endl;
		break;
	default:
		std::cout << std::endl;
		DisplayArray(golfScores, counter);
		std::cout << "\nThe average of the scores you entered is " << ArrayAverage(golfScores, counter) << "." << std::endl;
		break;
	}
	

	std::cin.get();
	std::cin.get();

	return 0;
}

unsigned short ArrayInput(unsigned short ar[])
{
	unsigned short i;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << "Please enter score #" << (i + 1) << ": ";
		std::cin >> ar[i];

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.get();
			std::cout << "\aInput terminated." << std::endl;
			break;
		}
	}

	return i;
}

void DisplayArray(unsigned short ar[], unsigned short n)
{
	for (int i = 0; i < n; i++)
		std::cout << "Score #" << (i + 1) << ":\t" << ar[i] << std::endl;
}

float ArrayAverage(unsigned short ar[], unsigned short n)
{
	float average = 0.0f;

	for (int i = 0; i < n; i++)
	{
		average += ar[i];
	}
	
	return average /= n;
}
