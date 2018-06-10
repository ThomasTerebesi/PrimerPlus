#include <iostream>
#include <valarray>
#include <cstdlib>
#include <ctime>

const int SIZE = 12;
typedef std::valarray<int> vint;

void Show(const vint & v, int cols);

int main()
{
	vint valint(SIZE);

	srand(static_cast<int>(time(0)));

	int i;
	for (i = 0; i < SIZE; ++i)
		valint[i] = rand() % 10;

	std::cout << "Original array:" << std::endl;
	Show(valint, 3);							// show in three columns

	vint vcol(valint[std::slice(1, 4, 3)]);		// extract second column
	std::cout << "Second column:" << std::endl;
	Show(vcol, 1);

	vint vrow(valint[std::slice(3, 3, 1)]);		// extract second row
	std::cout << "Second row:" << std::endl;
	Show(vrow, 3);

	valint[std::slice(2, 4, 3)] = 10;			// assign to second column
	std::cout << "Set last column to 10:" << std::endl;
	Show(valint, 3);

	std::cout << "Set first column to sum of next two:" << std::endl;	
	valint[std::slice(0, 4, 3)] = 
		static_cast<vint>(valint[std::slice(1, 4, 3)]) + // '+' is not defined for slices, so cast to valarray<int>
		static_cast<vint>(valint[std::slice(2, 4, 3)]);
	Show(valint, 3);

	std::cin.get();
	
	return 0;
}

void Show(const vint & v, int cols)
{
	int lim = v.size();

	for (int i = 0; i < lim; i++)
	{
		std::cout.width(3);
		std::cout << v[i];

		if (i % cols == cols - 1)
			std::cout << std::endl;
		else
			std::cout << ' ';
	}

	if (lim % cols != 0)
		std::cout << std::endl;
}
