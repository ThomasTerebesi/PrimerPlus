#include <iostream>
#include <new>
#include <cstdlib>	// for exit() and EXIT_FAILURE

struct Big
{
	double stuff[20000];
};

int main()
{
	Big * pb;

	try
	{
		std::cout << "Trying to get a big block of memory:" << std::endl;
		pb = new Big[10000];	// 1,600,000,000 bytes
		std::cout << "Got past the new request:" << std::endl;
	}

	catch (std::bad_alloc & ba)
	{
		std::cout << "Caught the exception!" << std::endl;
		std::cout << ba.what() << std::endl;

		std::cin.get();

		exit(EXIT_FAILURE);
	}

	std::cout << "Memory successfully allocated." << std::endl;
	
	pb[0].stuff[0] = 4;
	std::cout << pb[0].stuff[0] << std::endl;
	
	delete[] pb;
	
	std::cin.get();

	return 0;
}