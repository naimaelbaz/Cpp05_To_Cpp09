#include <iostream>

class test
{
public:
	void print()
	{
		std::cout << "i'm test";
	}
};

class ss
{
public:
	void print()
	{
		std::cout << "i'm not test";
	}
};





int main()
{
	test * b = new test;
	ss * s = new ss;

	long long b1 = reinterpret_cast<long long>(s);
	long long b2 = (long long)(s);

	std::cout << reinterpret_cast<void*>(b1) << "\n";
	std::cout << (void*)b2 << "\n";
}