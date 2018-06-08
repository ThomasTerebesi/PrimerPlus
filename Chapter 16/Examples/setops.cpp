#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
	const int N = 6;
	std::string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" };
	std::string s2[N] = { "metal", "any", "food", "elegant", "deliver", "for" };

	std::set<std::string> A(s1, s1 + N);
	std::set<std::string> B(s2, s2 + N);

	std::ostream_iterator<std::string, char> out(std::cout, " ");

	std::cout << "Set A: ";
	copy(A.begin(), A.end(), out);
	std::cout << std::endl;

	std::cout << "\nSet B: ";
	copy(B.begin(), B.end(), out);
	std::cout << std::endl;

	std::cout << "\nUnion of A and B:" << std::endl;
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	std::cout << std::endl;

	std::cout << "\nIntersection of A and B:" << std::endl;
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	std::cout << std::endl;

	std::cout << "\nDifference of A and B:" << std::endl;
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	std::cout << std::endl;

	std::set<std::string> C;
	std::cout << "\nSet C:" << std::endl;
	set_union(A.begin(), A.end(), B.begin(), B.end(), std::insert_iterator<std::set<std::string>>(C, C.begin()));
	copy(C.begin(), C.end(), out);
	std::cout << std::endl;

	std::string s3("grungy");
	C.insert(s3);
	std::cout << "\nSet C after insertion:" << std::endl;
	// copy(C.begin(), C.end(), out);
	for (auto item : C)
		std::cout << item << " ";
	std::cout << std::endl;

	std::cout << "\nShowing a range:" << std::endl;
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	std::cout << std::endl;

	std::cin.get();

	return 0;
}