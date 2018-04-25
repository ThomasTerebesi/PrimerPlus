#include <iostream>

const int ARRAY_SIZE = 80;

char * Left(const char * str, int n = 1);

int main()
{
	char sample[ARRAY_SIZE];

	std::cout << "Enter a string:" << std::endl;
	std::cin.get(sample, ARRAY_SIZE);

	char *ps = Left(sample, 4);
	std::cout << ps << std::endl;

	delete[] ps;

	ps = Left(sample);
	std::cout << ps << std::endl;

	delete[] ps;

	std::cin.get();
	std::cin.get();

	return 0;
}


// This function returns a pointer to a new string consisting of the first n characters in the str string
char * Left(const char * str, int n)
{
	if (n < 0)
		n = 0;

	// optimization for when a huge number is entered
	int m = 0;
	while (m <= n && str[m])
		m++;

	char * p = new char[m + 1];

	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i]; // copy characters

	while (i <= n) // for strings longer than the string actually is
		p[i++] = '\0'; // set rest of the string to '\0'

	return p;
}
