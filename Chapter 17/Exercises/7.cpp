// compile with 7store.h and 7store.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "7store.h"

void ShowStr(const std::string & str);
void GetStrs(std::ifstream & ifs, std::vector<std::string> & strv);

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;
	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	std::cin.get();

	return 0;
}

void ShowStr(const std::string & str)
{
	std::cout << str << std::endl;
}

void GetStrs(std::ifstream & ifs, std::vector<std::string>& strv)
{
	std::size_t length;
	std::string str;

	char ch;

	while (ifs.peek() && !ifs.eof())
	{
		ifs.read((char *)&length, sizeof(std::size_t));
		
		for (std::size_t i = 0; i < length; i++)
		{
			ifs.read(&ch, sizeof(char));
			str.push_back(ch);
		}

		strv.push_back(str);
		str.clear();
	}
}
