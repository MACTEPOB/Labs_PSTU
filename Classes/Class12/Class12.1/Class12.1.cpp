#include <set>
#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

typedef multiset<double> ms;
typedef multiset<double>::iterator ms_it;

ms make_set(int n)
{
	ms tmp;
	double data;
	random_device rd;   
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 10);
	for (auto i = 0; i < n; i++)
	{
		data = dist(gen);
		tmp.insert(data);
	}
	return tmp;
}
void print_set(ms set)
{
	for (auto& i : set)
	{
		cout << i << " ";
	}
	cout << endl;
}
void push_average(ms& set)
{
	double avrg = 0;
	int size = 0;
	for (auto& i : set)
	{
		avrg += i;
		size++;
	}
	set.insert(avrg / size);
}
ms removeInrange(ms set, double begin, double end)
{
	auto left = set.lower_bound(begin);
	auto right = set.upper_bound(end);
	set.erase(left, right);
	return set;
}
ms min_max_addition(ms set)
{
	double min = 1000000, max = 0;
	for (auto& i : set)
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
	for (auto& i : set)
	{
		tmp.insert(i + max + min);
	}
	set.swap(tmp);
	return set;
}
int main()
{
	setlocale(LC_ALL, "rus");
	ms set;
	cout << "Укажите количество элементов: ";
	int n;
	cin >> n;
	set = make_set(n);
	print_set(set);
	cout << "Контейнер после добавления среднего арифметического: ";
	push_average(set);
	print_set(set);
	cout << "Укажите диапазон для удаления элементов: "; double begin, end;
	cin >> begin >> end;
	set = removeInrange(set, begin, end);
	cout << "Преобразованный контейнер: ";
	print_set(set);
	cout << "Контейнер после добавления минимального/максимального элемента к каждому: ";
	set = min_max_addition(set);
	print_set(set);
	return 0;
}