#include <iostream>

void SwapR(int& a, int& b);
void SwapP(int* p, int* q);
void SwapV(int a, int b);

int main()
{
	int wallet1 = 300;
	int wallet2 = 350;

	std::cout << "wallet1 = $" << wallet1;
	std::cout << "\t\twallet2 = $" << wallet2 << std::endl;

	std::cout << "\nUsing references to swap contents:" << std::endl;
	SwapR(wallet1, wallet2);
	std::cout << "wallet1 = $" << wallet1;
	std::cout << "\t\twallet2 = $" << wallet2 << std::endl;

	std::cout << "\nUsing pointers to swap contents again:" << std::endl;
	SwapP(&wallet1, &wallet2);
	std::cout << "wallet1 = $" << wallet1;
	std::cout << "\t\twallet2 = $" << wallet2 << std::endl;

	std::cout << "\nTrying to use passing by value:" << std::endl;
	SwapV(wallet1, wallet2);
	std::cout << "wallet1 = $" << wallet1;
	std::cout << "\t\twallet2 = $" << wallet2 << std::endl;

	std::cin.get();

	return 0;
}

void SwapR(int& a, int& b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void SwapP(int * p, int * q)
{
	int temp;

	temp = *p;
	*p = *q;
	*q = temp;
}

void SwapV(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}
