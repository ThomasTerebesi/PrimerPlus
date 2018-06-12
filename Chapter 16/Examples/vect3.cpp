#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
	std::string title;
	int rating;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review &rr);
void ShowReview(const Review &rr);

int main()
{
	std::vector<Review> books;
	Review temp;

	while (FillReview(temp))
	{
		std::cout << std::endl;
		books.push_back(temp);
	}

	int num = books.size();

	if (num > 0)
	{
		std::cout << "\nThank you. You entered the following " << books.size() << " reviews:" << std::endl;
		std::cout << "Rating\tBook" << std::endl;
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end());
		std::cout << "\nSorted by title:\nRating\tBook" << std::endl;
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end(), worseThan);
		std::cout << "\nSorted by rating:\nRating\tBook" << std::endl;
		for_each(books.begin(), books.end(), ShowReview);

		random_shuffle(books.begin(), books.end());
		std::cout << "\nAfter shuffling:\nRating\tBook" << std::endl;
		// for_each(books.begin(), books.end(), ShowReview);	
		for (auto x : books) // as seen on page 991
			ShowReview(x);
	}
	else
		std::cout << "\nNo entries." << std::endl;

	std::cin.get();

	return 0;
}

bool operator<(const Review & r1, const Review & r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool worseThan(const Review & r1, const Review & r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool FillReview(Review & rr)
{
	std::cout << "Enter book title (type 'quit' to quit): ";
	std::getline(std::cin, rr.title);

	if (rr.title == "quit")
		return false;

	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;

	if (!std::cin)
		return false;

	// get rest of input line
	while (std::cin.get() != '\n')
		continue;

	return true;
}

void ShowReview(const Review & rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}
