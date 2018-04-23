#include <iostream>

const int MAX = 5;

double* fillArray(double arr[], int limit);
void showArray(const double arr[], double* arrayEnd);
void revalue(double r, double ar[], double* arrayEnd);

int main()
{
	double properties[MAX];

	double* lastFilled = fillArray(properties, MAX);
	showArray(properties, lastFilled);

	if (lastFilled > properties)
	{
		std::cout << "\nEnter revaluation factor: ";
		double factor;
		while (!(std::cin >> factor))
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;

			std::cout << "\nBad input. Please enter a number: ";
		}

		revalue(factor, properties, lastFilled);
		showArray(properties, lastFilled);

		std::cout << "\nDone." << std::endl;
		std::cin.get();
	}

	std::cin.get();
	return 0;
}

double* fillArray(double arr[], int limit)
{
	double temp;
	int i;

	for (i = 0; i < limit; i++)
	{
		std::cout << "Enter value #" << (i + 1) << ": ";
		std::cin >> temp;

		if (!std::cin)
		{
			std::cin.clear();

			while (std::cin.get() != '\n')
				continue;

			std::cout << "Bad input; input process terminated.";
			break;
		}
		else if (temp < 0)
			break;

		arr[i] = temp;
	}

	return arr + i;
}

void showArray(const double arr[], double* arrayEnd)
{
	const double* ap = arr;

	std::cout << std::endl;
	for (int i = 0; ap < arrayEnd; i++, ap++)
	{
		std::cout << "Property #" << (i + 1) << ": $";
		std::cout << *ap << std::endl;
	}
}

void revalue(double r, double arr[], double* arrayEnd)
{
	const double* ap = arr;

	for (int i = 0; ap < arrayEnd; i++, ap++)
		arr[i] *= r;
}