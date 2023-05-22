#include <iostream>
#include "digit.h"
using namespace std;

void digit::Read()
{
	cout << "first?: ";
	cin >> first;
	cout << "second?: ";
	cin >> second;
}

void digit::Init(int F, double S)
{
	first = F;
	second = S;
}

void digit::multiply(int k)
{
	double result = first + second;
	result *= k;
	cout << "Number = " << result << endl;
}