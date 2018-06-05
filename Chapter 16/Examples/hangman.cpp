#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

const int NUM = 26;
const std::string WORD_LIST[NUM] =	{ "apiary", "beetle", "cereal",
		"danger", "ensign", "florid", "garage", "health", "insult",
		"jackal", "keeper", "loaner", "manage", "nonce", "onset",
		"plaid", "quilt", "remote", "stolid", "train", "useful",
		"valid", "whence", "xenon", "yearn", "zippy" };

int main()
{
	srand(static_cast<int>(time(0)));

	char play;
	std::cout << "Will you play a word game? <y/n> ";
	std::cin >> play;
	play = tolower(play);

	while (play == 'y')
	{
		std::string target = WORD_LIST[rand() % NUM];
		int length = target.length();
		std::string attempt(length, '-');
		std::string badChars;
		int guesses = 6;

		std::cout << "Guess my secret word. It has " << length << " letters, and you guess" << std::endl;
		std::cout << "one letter at a time. You get " << guesses << " wrong guesses." << std::endl;

		std::cout << "\nYour word: " << attempt << std::endl;

		while (guesses > 0 && attempt != target)
		{
			char letter;
			std::cout << "\nGuess a letter: ";
			std::cin >> letter;
	
			if (badChars.find(letter) != std::string::npos || attempt.find(letter) != std::string::npos)
			{
				std::cout << "You already guessed that. Try again." << std::endl;
				continue;
			}

			int loc = target.find(letter);
			if (loc == std::string::npos)
			{
				std::cout << "Oh, bad guess!" << std::endl;
				guesses--;
				badChars += letter;	// add to string
			}
			else
			{
				std::cout << "Good guess!" << std::endl;
				attempt[loc] = letter;

				// check if letter appears again
				loc = target.find(letter, loc + 1);
				while (loc != std::string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}

			std::cout << "Your word: " << attempt << std::endl;

			if (attempt != target)
			{
				if (badChars.length() > 0)
					std::cout << "Bad choices: " << badChars << std::endl;
				std::cout << guesses << " bad guesses left." << std::endl;
			}
		}

		if (guesses > 0)
			std::cout << "That's right!" << std::endl;
		else
			std::cout << "Sorry, the word is " << target << "." << std::endl;

		std::cout << "\nWill you play another? <y/n> ";
		std::cin >> play;
		play = tolower(play);
	}

	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}