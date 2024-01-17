//function templates
//class templates

// templates is a way to write a generic programme (work with deff data types)

// deff between typeame and class in temp ?
// how to use class templates ?

#include <iostream>

// template <class T1>

// void getMax(T1 a)
// {
// 	// std::cout << sizeof(T) << "\n";
// 	static int v = 5;
// 	std::cout << ++v << "\n";
// 	// return (a > b ? a : b);
// }

// void getMax(double a)
// {
// 	// std::cout << sizeof(T) << "\n";
// 	static int v = 5;
// 	std::cout << ++v << "\n";
// 	// return (a > b ? a : b);
// }



// int main()
// {
// 	getMax(1);
// 	getMax('1');
// 	getMax(1.5);
	
// 	return 0;
// }

#include <iostream>

// Function template that takes a function and its parameters
// template <typename Func, typename Arg1, typename Arg2>
// void processFunction(Func func, Arg1 arg1, Arg2 arg2) {
//     func(arg1, arg2);
// }

// // Example function to be passed as a parameter
// void printSum(int a, int b) {
//     std::cout << "Sum: " << a + b << std::endl;
// }


// template <> void arr(int a, int b)
// {
// 	std::cout << a + b << "\n";
// }

// int main() 
// {
// 	int a = 5;
// 	int b = 4;
// 	arr(a, b);
// 	return 0;
// }


// template <typename T>

// T *add(T *a, T *b)
// {
// 	T *c = new T[8];
// 	for (int i = 0; i < 8; i++)
// 	{
// 		if (i < 4)
// 			c[i] = b[i];
// 		else
// 			c[i] = a[i - 4];
// 	}
// 	return(c);
// }

// int main()
// {
// 	int *f = new int[4];
// 	for (size_t i = 0; i < 4; i++)
// 		f[i] = int(1);
// 	int *g = new int[4];
// 	for (size_t i = 0; i < 4; i++)
// 		g[i] = int();
// 	int * c = NULL;
// 	c = add(f, g);
// 	for (int i = 0; i < 8; i++)
// 		std::cout << c[i] << "\n";
// }

