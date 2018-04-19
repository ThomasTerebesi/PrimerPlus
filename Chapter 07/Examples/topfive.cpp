#include <iostream>
#include <string>

const int SIZE = 5;

void Display(const std::string sa[], int n);

int main()
{
	std::string list[SIZE];
	std::cout << "Enter your " << SIZE << " favorite astronomical sights:" << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << (i + 1) << ": ";
		getline(std::cin, list[i]);
	}

	std::cout << "Your list:" << std::endl;
	Display(list, SIZE);

	std::cin.get();

	return 0;
}

void Display(const std::string sa[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << (i + 1) << ": " << sa[i] << std::endl;
}
