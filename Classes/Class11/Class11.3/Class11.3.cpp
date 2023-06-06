#include "list.h"
#include "Pair.h"
#include <iostream>


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������ ������: "; 
	int n;  
	cin >> n;
	List<Pair> l;
	for (int i = 0; i < n; i++)
	{
		Pair data;
		data.randomize();
		l.push(data);
	}
	cout << l << endl;
	cout << l.Avrg() << endl;
	l.push(l.Avrg());
	cout << "������ ����� ���������� �������� ��������������� � �����: ";
	cout << l << endl;
	cout << "�������� ��� ��������:\n"; 
	Pair p1, p2;
	cin >> p1 >> p2;
	List<Pair> tmp;
	for (int i = 0; i < l(); i++)
	{
		if (!(l[i] > p1 && l[i] < p2)) tmp.push(l[i]);
	}
	l = tmp;
	cout << "������ ����� �������� ���������: ";
	cout << l << endl;
	cout << "������ ����� ���������� ������������/������������� ��������� � �������: ";
	Pair max = l.Max();
	Pair min = l.Min();
	for (int i = 0; i < l(); i++)
	{
		l[i] += min;
		l[i] += max;
	}
	cout << l << endl;
	return 0;
}