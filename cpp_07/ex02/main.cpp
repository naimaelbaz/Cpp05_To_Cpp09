#include <iostream>
#include "Array.hpp"

int main()
{
	// Instantiate as int
	Array<int> objInt(5);
	for (int i = 0; i < 5; i++)
	{
		objInt[i] = int(i);
		std::cout << "obj[" << i << "] = " << objInt[i] << "\n";
	}

	// Instantiate as string
	Array<std::string> objString(5);
	for (int i = 0; i < 5; i++)
	{
		objString[i] = "hello";
		std::cout << "obj[" << i << "] = " << objString[i] << "\n";
	}
	return 0;
}