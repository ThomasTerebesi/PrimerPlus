#include <iostream>

// template prototypes
template <typename T>
void Counts();

template <typename T>
void Report(T &);

// template class
template <typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT & i) : item(i) { ct++; }
	~HasFriendT() { ct--; }
	friend void Counts<TT>();
	friend void Report<HasFriendT<TT>>(HasFriendT<TT> &);
};

template <typename T>
int HasFriendT<T>::ct = 0;

// template friend functions definitions
template <typename T>
void Counts()
{
	std::cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
	std::cout << "template Counts(): " << HasFriendT<T>::ct << std::endl;
}

template <typename T>
void Report(T & ref)
{
	std::cout << ref.item << std::endl;
}


int main()
{
	Counts<int>();

	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);

	Report(hfi1);
	Report(hfi2);
	Report(hfdb);

	std::cout << "Counts<int>() output:" << std::endl;
	Counts<int>();

	std::cout << "Counts<double>() output:" << std::endl;
	Counts<double>();

	std::cin.get();

	return 0;
}
