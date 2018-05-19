// compile with 2string2.h and 2string2.cpp

#include <iostream>
#include "2string2.h"

int main()
{
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;

	std::cout << s2;
	std::cin >> s3;
	s2 = "My name is " + s3;
	std::cout << s2 << std::endl;
	s2 = s2 + s1;
	s2.StringUp();
	std::cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
		<< " 'A' characters in it" << std::endl;
	s1 = "red";
	String rgb[3] = { String(s1), String("green"), String("blue") };
	std::cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (std::cin >> ans)
	{
		ans.StringLow();
		for (int i = 0; i < 3; ++i)
		{
			if (ans == rgb[i])
			{
				std::cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			std::cout << "Try again!" << std::endl;
	}
	std::cout << "Bye!" << std::endl;

	std::cin.get();

	return 0;
}