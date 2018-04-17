#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::cout << "Enter words (q to quit):" << std::endl;

	std::string word = "";
	std::cin >> word;

	char initialChar = ' ';
	unsigned short vowelCount = 0;
	unsigned short consonantCount = 0;
	unsigned short otherCount = 0;

	while (word != "q")
	{
		initialChar = word[0];

		if (isalpha(initialChar))
		{
			switch (initialChar)
			{
			case 'a':
				vowelCount++;
				break;
			case 'e':
				vowelCount++;
				break;
			case 'i':
				vowelCount++;
				break;
			case 'o':
				vowelCount++;
				break;
			case 'u':
				vowelCount++;
				break;
			case 'A':
				vowelCount++;
				break;
			case 'E':
				vowelCount++;
				break;
			case 'I':
				vowelCount++;
				break;
			case 'O':
				vowelCount++;
				break;
			case 'U':
				vowelCount++;
				break;
			default:
				consonantCount++;
				break;
			}
		}
		else
			otherCount++;

		std::cin >> word;
	}

	std::cout << "\n" << vowelCount << " words beginning with vowels." << std::endl;
	std::cout << consonantCount << " words beginning with consonants." << std::endl;
	std::cout << otherCount << " words beginning with other characters." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}