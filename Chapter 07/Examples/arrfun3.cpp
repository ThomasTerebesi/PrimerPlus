#include <iostream>

const int MAX = 5;

int fillArray(double arr[], int limit);
void showArray(const double arr[], int n);
void revalue(double r, double ar[], int n);

int main()
{
	double properties[MAX];

	int size = fillArray(properties, MAX);
	showArray(properties, size);

	if (size > 0)
	{
		std::cout << "Enter revaluation factor: ";
		
		double factor;
		while (!(std::cin >> factor))
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;

			std::cout << "Bad input. Please enter a number: ";
		}

		revalue(factor, properties, size);
		showArray(properties, size);
	}

	std::cout << "Done." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}

int fillArray(double arr[], int limit)
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

			std::cout << "Bad input; input process terminated." << std::endl;
			break;
		}
		else if (temp < 0)
			break;

		arr[i] = temp;
	}

	return i;
}

void showArray(const double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Property #" << (i + 1) << ": $";
		std::cout << arr[i] << std::endl;
	}
}

void revalue(double r, double arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] *= r;
}