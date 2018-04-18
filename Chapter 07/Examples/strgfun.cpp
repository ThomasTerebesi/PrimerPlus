#include <iostream>

unsigned int cInStr(const char* str, char ch);

int main()
{
	char mmm[15] = "minimum";

	const char *wail = "ululate";

	unsigned int ms = cInStr(mmm, 'm');
	unsigned int us = cInStr(wail, 'u');

	std::cout << ms << " m characters in " << mmm << std::endl;
	std::cout << us << " u characters in " << wail << std::endl;

	std::cin.get();
	return 0;
}

unsigned int cInStr(const char* str, char ch)
{
	unsigned int count = 0;

	while (*str)
	{
		if (*str == ch)
			count++;
		str++;
	}
	return count;
}