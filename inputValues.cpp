/*
  Inputing values for linear congruences
*/

#include <iostream>
#include <vector>
#include "inputValues.h"

void inputValues(int size, std::vector<int>& a, std::vector<int>& n)
{
	int c;
	int m;

	for (int i = 0; i < size; i++)
	{
		std::cout << "\nEnter a" << i + 1 << ": ";

		std::cin >> c;
		a.push_back(c);

		std::cout << "Enter n" << i + 1 << ": ";

		std::cin >> m;
		n.push_back(m);
	}
}