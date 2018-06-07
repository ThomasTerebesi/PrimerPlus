#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

void Output(const std::string & s) { std::cout << s << ' '; }

int main()
{
	std::string s1[4] = { "fine", "fish", "fashion", "fate" };
	std::string s2[2] = { "busy", "bats" };
	std::string s3[2] = { "silly", "singers" };

	std::vector<std::string> words(4);

	copy(s1, s1 + 4, words.begin());
	// for_each(words.begin(), words.end(), Output);
	for (auto word : words)
		Output(word);
	std::cout << std::endl;

	// construct anonymous back_insert_iterator object
	copy(s2, s2 + 2, std::back_insert_iterator<std::vector<std::string>>(words));
	for_each(words.begin(), words.end(), Output);
	std::cout << std::endl;

	// construct anonymous insert_iterator object
	copy(s3, s3 + 2, std::insert_iterator<std::vector<std::string>>(words, words.begin()));
	for_each(words.begin(), words.end(), Output);
	std::cout << std::endl;

	std::cin.get();

	return 0;
}