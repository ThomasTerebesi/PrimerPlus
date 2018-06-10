#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

char toLower(char ch) { return tolower(ch); }
std::string & ToLower(std::string & st);
void Display(const std::string & st);

int main()
{
	std::vector<std::string> words;
	std::cout << "Enter words (enter 'quit' to quit):" << std::endl;
	std::string input;
	while (std::cin >> input && input != "quit")
		words.push_back(input);

	std::cout << "\nYou entered the following words:" << std::endl;
	for (auto item : words)
		Display(item);
	std::cout << std::endl;

	// place words in set, converting to lowercase
	std::set<std::string> wordset;
	transform(words.begin(), words.end(), std::insert_iterator<std::set<std::string>>(wordset, wordset.begin()), ToLower);
	std::cout << "\nAlphabetic list of words:" << std::endl;
	for (auto item : wordset)
		Display(item);
	std::cout << std::endl;

	// place word and frequency in map
	std::map<std::string, int> wordmap;
	std::set<std::string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = count(words.begin(), words.end(), *si);

	// display map contents
	std::cout << "\nWord frequency:" << std::endl;
	for (si = wordset.begin(); si != wordset.end(); si++)
		std::cout << *si << ": " << wordmap[*si] << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}

std::string & ToLower(std::string & st)
{
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}

void Display(const std::string & st)
{
	std::cout << st << ' ';
}
