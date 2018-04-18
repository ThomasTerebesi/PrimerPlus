#include <iostream>

char* buildstr(char c, int n);

int main()
{
	unsigned short times;
	char ch;

	std::cout << "Enter a character: ";
	std::cin >> ch;

	std::cout << "Enter an integer: ";
	std::cin >> times;

	char *ps = buildstr(ch, times);
	std::cout << ps << std::endl;

	delete[] ps;
	
	ps = buildstr('+', 20);

	std::cout << ps << "-DONE-" << ps << std::endl;

	delete[] ps;

	std::cin.get();
	std::cin.get();

	return 0;
}

// builds a string made of n c characters
char* buildstr(char c, int n)
{
	char* pstr = new char[n + 1];
	pstr[n] = '\0';
	while (n-- > 0)
		pstr[n] = c;
	return pstr;
}
