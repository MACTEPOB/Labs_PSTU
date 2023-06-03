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
		List first(0);
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
	}
	catch (int num)
	{
		cout << "Ошибка с кодом: " << num << endl;
		cout << "1 - выбранный размер множества недопустим. 2 - выбранный индекс недопустим. 3 - нельзя удалить элемент, размер равен 0" << endl;
	}
	return 0;
}