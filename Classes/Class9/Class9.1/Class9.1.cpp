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
		cout << "������� � ��������� ��������: " << first[0] << endl;
		cout << "������ ���������: " << first() << endl;
		List second(2);
		second.show();
		List third(2);
		third = first - second;
		third.show();
	}
	catch (int num)
	{
		cout << "������ � �����: " << num << endl;
		cout << "1 - ��������� ������ ��������� ����������. 2 - ��������� ������ ����������. 3 - ������ ������� �������, ������ ����� 0" << endl;
	}
	return 0;
}