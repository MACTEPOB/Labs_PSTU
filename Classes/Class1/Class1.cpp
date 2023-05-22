#include <iostream>
#include "digit.h"

using namespace std;

int main()
{
	cout << "showcase with num 5.62 and k = 5\n";
	digit firstNumber;
	firstNumber.Init(5, 0.62);
	firstNumber.multiply(5);
	cout << "now set ur own num\n";
	digit secondNumber;
	int k;
	secondNumber.Read();
	cout << "k?: ";
	cin >> k;
	secondNumber.multiply(k);
}