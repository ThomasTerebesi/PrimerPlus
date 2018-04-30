#include <iostream>
#include <new> // for placement new

const int BUFFER_SIZE = 512;
const int N = 5;

char buffer[BUFFER_SIZE];

int main()
{
	double *pd1, *pd2;
	int i;
	std::cout << "Calling new and placement new:" << std::endl;
	pd1 = new double[N]; // use heap
	pd2 = new (buffer) double[N]; // use buffer array
	
	for (i = 0; i < N; i++)
		pd1[i] = pd2[i] = 1000 + 20.0 * i;
	
	std::cout << "Memory addresses:" << std::endl;
	std::cout << "Heap: " << pd1 << "\tStatic: " << (void *)buffer << std::endl;

	std::cout << "Memory contents:" << std::endl;
	for (i = 0; i < N; i++)
	{
		std::cout << pd1[i] << " at " << &pd1[i] << "; ";
		std::cout << pd2[i] << " at " << &pd2[i] << std::endl;
	}


	std::cout << "\nCalling new and placement new a second time:" << std::endl;
	double *pd3, *pd4;
	pd3 = new double[N]; // find new address
	pd4 = new (buffer) double[N]; // overwrite old data

	for (i = 0; i < N; i++)
		pd3[i] = pd4[i] = 1000 + 40.0 * i;

	std::cout << "Memory contents:" << std::endl;
	for (i = 0; i < N; i++)
	{
		std::cout << pd3[i] << " at " << &pd3[i] << "; ";
		std::cout << pd4[i] << " at " << &pd4[i] << std::endl;
	}


	std::cout << "\nCalling new and placement new a third time:" << std::endl;
	delete[] pd1;
	pd1 = new double[N]; // find new address
	pd2 = new (buffer + N * sizeof(double)) double[N]; // overwrite old data

	for (i = 0; i < N; i++)
		pd1[i] = pd2[i] = 1000 + 60.0 * i;

	std::cout << "Memory contents:" << std::endl;
	for (i = 0; i < N; i++)
	{
		std::cout << pd1[i] << " at " << &pd1[i] << "; ";
		std::cout << pd2[i] << " at " << &pd2[i] << std::endl;
	}

	delete[] pd1;
	delete[] pd3;

	// can't use delete[] with placement new, because buffer is static memory

	std::cin.get();

	return 0;
}