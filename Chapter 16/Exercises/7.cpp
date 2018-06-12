#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

std::vector<short> Lotto(const short spots, const short selection);

int main()
{
	srand(static_cast<int>(time(0)));

	short userSpots, userSelection;

	std::cout << "Please enter the number of spots in your lottery game: ";
	std::cin >> userSpots;
	std::cout << "Please enter the number of spots to be selected: ";
	std::cin >> userSelection;

	std::cout << std::endl;

	std::vector<short> winners = Lotto(userSpots, userSelection);

	short* userChoice = new short[userSelection];

	short input;
	int i;

	for (i = 0; i < userSelection; i++)
	{
		std::cout << "Please enter choice #" << (i + 1) << ": ";
		std::cin >> input;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "\aInvalid input. Try again: ";
			std::cin >> input;
		}

		while (input < 1)
		{
			std::cout << "\aValues must be greater than 0. Please enter a valid value: ";
			std::cin >> input;
		}

		while (input > userSpots)
		{
			std::cout << "\aValues must be less than " << userSpots << ". Please enter a valid value: ";
			std::cin >> input;
		}

		// checks for duplicates
		while (i != 0 && *(std::find(userChoice, userChoice + i, input)) == input)
		{
			std::cout << "\aYou already entered " << input << ". Please enter a different value: ";
			std::cin >> input;
		}

		userChoice[i] = input;
	}

	std::cout << "\nHere are your entries: ";
	for (i = 0; i < userSelection; i++)
		std::cout << userChoice[i] << "  ";
	std::cout << std::endl;

	std::vector<short> hits;
	unsigned short hitCount = 0;

	std::cout << "\nAnd here are the lucky numbers: ";
	for (auto number : winners)
	{
		std::cout << number << "  ";
		for (i = 0; i < userSelection; i++)
		{
			if (number == userChoice[i])
			{
				hits.push_back(number);
				hitCount++;
			}
		}
	}
	std::cout << std::endl;

	std::cout << "\nYou hit " << hitCount << " numbers." << std::endl;
	if (hitCount == 0)
	{
		std::cout << "Better luck next time!" << std::endl;
	}
	else if (hitCount == 1)
	{
		std::cout << "Your lucky number was " << hits[0] << std::endl;
	}
	else
	{
		std::cout << "Nice! Your lucky numbers are: ";
		for (auto number : hits)
			std::cout << number << "  ";
		std::cout << std::endl;
	}

	std::cin.get();
	std::cin.get();

	delete[] userChoice;

	return 0;
}

std::vector<short> Lotto(const short spots, const short selection)
{
	if (spots < 1 || selection < 1)
	{
		std::cout << "\aArguments must be greater than 0. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	else if (spots < selection)
	{
		std::cout << "\aNumber of spots must not be smaller than the selection. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::vector<short> tempRange;

	for (int i = 0; i < spots; i++)
		tempRange.push_back(i + 1);

	random_shuffle(tempRange.begin(), tempRange.end());

	return std::vector<short>(tempRange.begin(), tempRange.begin() + selection);
}


