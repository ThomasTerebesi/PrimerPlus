#include <cstdio>
#include <iostream>

int main()
{
	std::cout << "This system can generate up to " << TMP_MAX
		<< " temporary names of up to " << L_tmpnam
		<< " characters." << std::endl;

	char pszName[L_tmpnam] = { '\0' };

	std::cout << "\nHere are ten names:" << std::endl;

	for (int i = 0; 10 > i; i++)
	{
		tmpnam_s(pszName);
		std::cout << pszName << std::endl;
	}

	std::cin.get();

	return 0;
}