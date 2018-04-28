#include <iostream>

template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T * arr[], int n);

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T * arr[], int n);



struct Debts
{
	char name[50];
	double amount;
};


int main()
{
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	Debts mrE[3] =
	{
		{ "Ima Wolfe", 2400.0 },
		{ "Ura Foxe", 1300.0 },
		{ "Iby Stout", 1800.0 }
	};
	double * pd[3];

	// set pointers to the amount members of the structures in mrE
	for (int i = 0; i < 3; i++)
		pd[i] = &mrE[i].amount;

	std::cout << "Listing Mr. E's counts of things:" << std::endl;
	// things is an array of int
	ShowArray(things, 6); // uses template A
	std::cout << "Total things: " << SumArray(things, 6) << std::endl;

	std::cout << "\nListing Mr. E's debts:" << std::endl;
	// pd is an array of pointers to double
	ShowArray(pd, 3);
	std::cout << "Total debts: " << SumArray(pd, 3) << std::endl;

	std::cin.get();

	return 0;
}

template<typename T>
void ShowArray(T arr[], int n)
{
	std::cout << "Template A:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

template<typename T>
void ShowArray(T * arr[], int n)
{
	std::cout << "Template B:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << *arr[i] << ' ';
	std::cout << std::endl;
}

template<typename T>
T SumArray(T arr[], int n)
{
	T result = 0;

	for (int i = 0; i < n; i++)
		result += arr[i];

	return result;
}

template<typename T>
T SumArray(T * arr[], int n)
{
	T result = 0;
	
	for (int i = 0; i < n; i++)
		result += *arr[i];
	
	return result;
}
