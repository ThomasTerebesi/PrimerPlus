#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

const int CONTAINER_SIZE = 1048576;	// 2 ^ 20

int main()
{
	srand(static_cast<int>(time(0)));

	std::vector<int> vi0(CONTAINER_SIZE, 0);
	for (int i = 0; i < CONTAINER_SIZE; i++)
		vi0.at(i) = (rand() % 2048) + 1;

	std::vector<int> vi(vi0.begin(), vi0.end());
	std::list<int> li(vi0.begin(), vi0.end());
	
	std::cout << "Sorting vector..." << std::endl;
	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	std::cout << "\a\tDone. Execution time in seconds: " << static_cast<double>((end - start) / CLOCKS_PER_SEC) << std::endl;

	std::cout << "\nSorting list..." << std::endl;
	start = clock();
	li.sort();
	end = clock();
	std::cout << "\a\tDone. Execution time in seconds: " << static_cast<double>((end - start) / CLOCKS_PER_SEC) << std::endl;

	
	copy(vi0.begin(), vi0.end(), li.begin());
	std::cout << "\nList has been reset to its original, unsorted values." << std::endl;
	std::cout << "\nCopying list into vector, sorting vector and copying the vector's contents back to the initial list..." << std::endl;
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	std::cout << "\a\tDone. Execution time in seconds: " << static_cast<double>((end - start) / CLOCKS_PER_SEC) << std::endl;

	std::cin.get();

	return 0;
}