#include<iostream>
#include<ctime>
#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	try
	{
		List first(3);
		first.show();
		--first;
		first.show();
		cout << "Элемент с избранным индексом: " << first[0] << endl;
		cout << "Размер множества: " << first() << endl;
		List second(2);
		second.show();
		List third(2);
		third = first - second;
		third.show();
		cout << "Элемент с избранным индексом: " << first[5] << endl;
	}
	catch (error ER)
	{
		ER.what();
	}
	return 0;
}