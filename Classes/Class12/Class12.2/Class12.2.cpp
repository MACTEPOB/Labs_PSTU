#include <set>
#include <algorithm>
#include <iostream>
#include "pair.h"
using namespace std;

typedef multiset<Pair> ms;

ms make_set(ms set, int n)
{

	for (int i = 0; i < n; i++)
	{
		Pair data;
		data.randomize();
		set.insert(data);
	}
	return set;
}
void print_set(ms set)
{
	for (auto& i : set)
	{
		cout << i << " ";
	}
	cout << '\n';
}
void push_average(ms& set)
{
	Pair avrg;
	for (auto& i : set)
	{
		avrg += i;
	}
	set.insert(avrg / set.size());
}
ms removeInrange(ms set, Pair begin, Pair end)
{
	auto left = set.lower_bound(begin);
	auto right = set.upper_bound(end);
	set.erase(left, right);
	return set;
}
ms min_max_addition(ms set)
{
	Pair max(0, 0), min(100000, 100000);
	for (auto i : set)
	{
		if (min > i)
		{
			min = i;
		}
		else if (max < i)
		{
			max = i;
		}
	}

	ms tmp;
	for (Pair i : set)
	{
		tmp.insert(i + max + min);
	}
	tmp.swap(set);
	return set;
}
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Укажите количество элементов: ";
	int n;
	cin >> n;
	ms set;
	set = make_set(set, n);
	print_set(set);
	cout << "Контейнер после добавления среднего арифметического: ";
	push_average(set);
	print_set(set);
	cout << "Введите диапазон для удаления элементов:\n";
	Pair begin, end;
	cin >> begin >> end;
	set = removeInrange(set, begin, end);
	cout << "Контейнер после преобразований: ";
	print_set(set);
	cout << "Контейнер после добавления минимального/максимального элементов к каждому элементу: ";
	set = min_max_addition(set);
	print_set(set);
	return 0;
}