#include <iostream>
#include <string>

int main()
{
	std::string s1 = "penguin";
	std::string s2, s3;

	std::cout << "You can assign one string object to another: s2 = s1\n";
	s2 = s1;
	std::cout << "s1: " << s1 << ", s2: " << s2 << std::endl;
	std::cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	std::cout << "s2: " << s2 << std::endl;
	std::cout << "You can concatenate strings: s3 = s1 + s2\n";
	s3 = s1 + s2;
	std::cout << "s3: " << s3 << std::endl;
	std::cout << "You can append strings.\n";
	s1 += s2;
	std::cout << "s1 += s2 yields s1 = " << s1 << std::endl;
	s2 += " for a day";
	std::cout << "s2 += \" for a day\" yields s2 = " << s2 << std::endl;

	std::cin.get();
	return 0;
}