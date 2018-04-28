#include <iostream>
#include <cstring>

template<typename T>
T MaxN(T arr[], int n);

template<>
const char * MaxN(const char* arr[], int n);

int main()
{
	int intArray[6] = { 12, 69, 98, 33, 420, 217 };
	double doubleArray[4] = { 43.24, 56.1, 19.73, 25.3 };
	const char * charArray[5] = {
		"\"The best revenge is not to be like your enemy.\" - Marcus Aurelius",
		"\"If it is not right, do not do it, it it is not true, do not say it.\" - Marcus Aurelius",
		"\"He who fears death will never do anything worth of a man who is alive.\" - Seneca",
		"\"Waste no more time arguing what a good man should be. Be one.\" - Marcus Aurelius",
		"\"If a man knows not which port he sails, no wind is favorable.\" - Seneca"
	};

	std::cout << "Largest number in intArray:" << std::endl;
	std::cout << MaxN(intArray, 6) << std::endl;

	std::cout << "\nLargest number in doubleArray:" << std::endl;
	std::cout << MaxN(doubleArray, 4) << std::endl;

	std::cout << "\nLongest string in charArray:" << std::endl; 
	std::cout << MaxN(charArray, 5) << std::endl;

	std::cin.get();

	return 0;
}

template<typename T>
T MaxN(T arr[], int n)
{
	T largest = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (largest < arr[i])
			largest = arr[i];
	}

	return largest;
}

template<>
const char * MaxN(const char * arr[], int n)
{
	const char * longest = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (strlen(longest) < strlen(arr[i]))
			longest = arr[i];
	}

	return longest;
}
