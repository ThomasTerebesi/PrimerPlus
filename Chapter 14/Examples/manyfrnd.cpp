#include <iostream>

template <typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T & i) : item(i) {}
	
	template <typename C, typename D>
	friend void Show2(C &, D &);
};

template<typename C, typename D>
void Show2(C & c, D & d)
{
	std::cout << c.item << ", " << d.item << std::endl;
}

int main()
{
	ManyFriend<int> mfi1(10);
	ManyFriend<int> mfi2(20);
	ManyFriend<double> mfdb(10.5);

	std::cout << "mfi1, mfi2: ";
	Show2(mfi1, mfi2);

	std::cout << "\nmfdb, mfi2: ";
	Show2(mfdb, mfi2);

	std::cin.get();

	return 0;
}
