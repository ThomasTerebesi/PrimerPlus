#include <iostream>

template <typename T>
class Beta
{
private:
	template <typename V>
	class Hold
	{
	private:
		V val;
	public:
		Hold(V v = 0) : val(v) {}
		void Show() const { std::cout << val << std::endl; }
		V Value() const { return val; }
	};

	Hold<T> q;		// template object
	Hold<int> n;	// template object

public:
	Beta(T t, int i) : q(t), n(i) {}
	void Show() const { q.Show(); n.Show(); }

	template<typename U>	// template method
	U Blab(U u, T t) { return static_cast<U>((n.Value() + q.Value()) * u / t); }
};

int main()
{
	Beta<double> guy(3.5, 3);

	std::cout << "T was set to double." << std::endl;
	guy.Show();

	std::cout << "V was set to T, which is double, then V was set to int.\n" << std::endl;
	std::cout << guy.Blab(10, 2.3) << std::endl;
	std::cout << "U was set to int.\n" << std::endl;

	std::cout << guy.Blab(10.0, 2.3) << std::endl;
	std::cout << "U was set to double." << std::endl;

	std::cout << "\nDone." << std::endl;

	std::cin.get();
}