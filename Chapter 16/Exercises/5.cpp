#include <iostream>
#include <string>
#include <algorithm>

const short ARRAY_SIZE = 10;

template<typename T>
int Reduce(T ar[], int n);

template<typename T>
void ShowArray(T ar[], int n);

int main()
{
	long longArray[ARRAY_SIZE] = { 7, 23, 94, 37, 92, 23, 65, 37, 7, 92 };

	std::cout << "Contents of longArray after initialization:" << std::endl;
	ShowArray(longArray, ARRAY_SIZE);

	int longArraySize = Reduce(longArray, ARRAY_SIZE);
	std::cout << "\nContents of longArray after sorting and removing duplicates:" << std::endl;
	ShowArray(longArray, longArraySize);
	std::cout << "\t\tSize of longArray: " << longArraySize << std::endl;

	std::string stringArray[ARRAY_SIZE] =
	{
		"danger", "beetle", "health",
		"danger", "jackal", "florid",
		"garage", "health", "insult",
		"jackal"
	};

	std::cout << "\nContents of stringArray after initialization:" << std::endl;
	ShowArray(stringArray, ARRAY_SIZE);

	int stringArraySize = Reduce(stringArray, ARRAY_SIZE);
	std::cout << "\nContents of stringArray after sorting and removing duplicates:" << std::endl;
	ShowArray(stringArray, stringArraySize);
	std::cout << "\t\tSize of stringArray: " << stringArraySize << std::endl;

	std::cin.get();

	return 0;
}

template<typename T>
int Reduce(T ar[], int n)
{
	std::sort(ar, ar + n);

	auto arrayEnd = std::unique(ar, ar + n);

	return arrayEnd - ar;
}

template<typename T>
void ShowArray(T ar[], int n)
{
	std::cout << "\t\t";
	for (int i = 0; i < n; i++)
		std::cout << ar[i] << "  ";
	std::cout << std::endl;
}
