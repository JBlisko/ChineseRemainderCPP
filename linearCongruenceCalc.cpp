/*
   Linear Congruence Calculator: Made in my junior year of college. Solves linear congruences of the form sum(a_i*x_i)\equiv n_i. Will be used in Solutions to Diophantine eqns.
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "inputValues.h"

//void inputValues(int size, std::vector<int>& a, std::vector<int>& n);
void calcN(int size, std::vector<int> a, std::vector<int> n, int& N);
void calcZ(int size, std::vector<int> n, int N, std::vector<int>& z);
void calcY(std::vector<int> n, std::vector<int> z, std::vector<int>& y, int size);
void calcX(int size, int N, int& x, std::vector<int> a, std::vector<int> z, std::vector<int> y);
void finalOutput(std::vector<int> a, std::vector<int> n, int x, int size, int N);

int main()
{
	int size;
	int N = 1;
	int x = 0;
	char answer;
	std::vector<int> a;
	std::vector<int> n;
	std::vector<int> z;
	std::vector<int> y;

Start:

	std::cout << "Enter the amount of congruences that there are: ";
	std::cin >> size;

	inputValues(size, a, n);
	calcN(size, a, n, N);
	calcZ(size, n, N, z);
	calcY(n, z, y, size);

	if (y.size() < size)
	{
		std::cout << "\nThis linear congruence does not exist.\n\n";
	}
	else
	{
		calcX(size, N, x, a, z, y);
		finalOutput(a, n, x, size, N);
	}

	std::cout << "Would you like to solve another set of congruences? (y for yes or n for no): ";
Repeat:
	std::cin >> answer;

	if (answer == 'y')
	{
		N = 1;
		x = 0;
		a.clear();
		n.clear();
		z.clear();
		y.clear();
		system("cls");
		goto Start;
	}
	else if (answer == 'n')
	{
		std::cout << "\nThank you for using this program.\n\n";
		//system("pause");
		return 0;
	}
	else
	{
		system("cls");
		std::cout << "Please enter either y for yes or n for no: ";
		goto Repeat;
	}
}


/*
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
*/


void calcN(int size, std::vector<int> a, std::vector<int> n, int& N)
{
	for (int i = 0; i < size; i++)
	{
		N = n[i] * N;
	}
}

void calcZ(int size, std::vector<int> n, int N, std::vector<int>& z)
{
	for (int i = 0; i < size; i++)
	{
		z.push_back(N / n[i]);
	}
}

void calcY(std::vector<int> n, std::vector<int> z, std::vector<int>& y, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < n[i]; j++)
		{
			if ((z[i] * j) % n[i] == 1)
			{
				y.push_back(j);
			}
		}
	}
}

void calcX(int size, int N, int& x, std::vector<int> a, std::vector<int> z, std::vector<int> y)
{
	for (int i = 0; i < size; i++)
	{
		x = x + (a[i] * z[i] * y[i]);
	}

	x = x % N;
}

void finalOutput(std::vector<int> a, std::vector<int> n, int x, int size, int N)
{
	system("cls");
	std::cout << "The equivalencies that were input are the following:\n\n";

	for (int i = 0; i < size; i++)
	{
		std::cout << "x" << (char)240 << a[i] << " mod " << n[i] << std::endl;
	}

	std::cout << "\nThis gives a linear congruence of x" << (char)240 << x << " mod " << N << "\n\n";
}


