#include <iostream>
#include <string>
#include <cstring>

int main()
{
	char charr1[20];
	char charr2[20] = "jaguar";
	std::string str1;
	std::string str2 = "panther";

	str1 = str2; // copy str2 to str1
	strcpy_s(charr1, charr2); // copy charr2 to charr1

	str1 += " paste"; // add " paste" to end of str1
	strcat_s(charr1, " juice"); // add " juice" to end of charr1

	int len1 = str1.size(); // obtain length of str1
	int len2 = strlen(charr1); // obtain length of charr1

	std::cout << "The string " << str1 << " contains " << len1 << " characters.\n";
	std::cout << "The string " << charr1 << " contains " << len2 << " characters.\n";

	std::cin.get();
	return 0;
}