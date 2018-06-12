#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review
{
	std::string title;
	int rating;
	float price;
};

bool operator<(const Review & r1, const Review & r2);
bool WorseThan(const Review & r1, const Review & r2);
bool FillReview(std::vector<std::shared_ptr<Review>> & container);
void ShowReview(const std::shared_ptr<Review> rr);

int main()
{
	std::vector<std::shared_ptr<Review>> books;
	std::shared_ptr<Review> temp;

	while(FillReview(temp))

	int num = books.size();

	if (num > 0)
	{
		std::cout << "\nThank you. You entered the following " << books.size() << " reviews:" << std::endl;
		std::cout << "Rating\tBook\tPrice" << std::endl;
		for_each(books.begin(), books.end(), ShowReview);
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

bool WorseThan(const Review & r1, const Review & r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool FillReview(std::vector<std::shared_ptr<Review>> & container)
{


	std::cout << "Enter book title (type 'quit' to quit): ";
	std::getline(std::cin, rr.title);

	if (rr.title == "quit")
		return false;

	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;

	if (!std::cin)
		return false;

	std::cout << "Enter book price: ";
	std::cin >> rr.price;

	if (!std::cin)
		return false;

	// get rest of input line
	while (std::cin.get() != '\n')
		continue;

	return true;
}

void ShowReview(const std::shared_ptr<Review> rr)
{
	std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}
