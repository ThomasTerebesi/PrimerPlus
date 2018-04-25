#include <iostream>

template <typename T>
void Swap(T &a, T &b);

template <typename T>
void Swap(T *a, T *b, int n);

void Show(int a[]);

const int LIMIT = 8;

int main()
{
	int i = 10;
	int j = 20;

	std::cout << "i, j = " << i << ", " << j << "." << std::endl;
	std::cout << "Using compiler-generated int swapper:" << std::endl;
	Swap(i, j);
	std::cout << "After the swap, i, j = " << i << ", " << j << "." << std::endl;

	int d1[LIMIT] = { 0, 7, 0, 4, 1, 7, 7, 6 };
	int d2[LIMIT] = { 0, 7, 2, 0, 1, 9, 6, 9 };

	std::cout << "Original arrays:" << std::endl;
	Show(d1);
	Show(d2);
	Swap(d1, d2, LIMIT);

	std::cout << "Swapped arrays:" << std::endl;
	Show(d1);
	Show(d2);

	std::cin.get();

	return 0;
}

template<typename T>
void Swap(T & a, T & b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template<typename T>
void Swap(T * a, T * b, int n)
{
	T temp;

	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	std::cout << a[0] << a[1] << "/";
	std::cout << a[2] << a[3] << "/";

	for (int i = 4; i < LIMIT; i++)
		std::cout << a[i];
	std::cout << std::endl;
}
