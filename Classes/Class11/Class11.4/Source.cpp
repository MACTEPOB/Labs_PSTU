#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include "Pair.h"
#include <cstdlib>
#include "Windows.h"

typedef priority_queue<Pair> pri_queue;
typedef list<Pair> list_Pair;

pri_queue make_queue(int n)
{
	pri_queue q;
	Pair p;
	for (int i = 0; i < n; i++)
	{
		p.randomize();
		q.push(p);
	}
	return q;
}
list_Pair copy_queue_to_list(pri_queue q)
{
	list_Pair l;
	while (!q.empty())
	{
		l.push_back(q.top());
		q.pop();
	}
	return l;
}
pri_queue copy_list_to_queue(list_Pair l)
{
	pri_queue q;
	while (!l.empty())
	{
		q.push(l.front());
		l.pop_front();
	}
	return q;
}
Pair average(pri_queue& q)
{
	list_Pair l = copy_queue_to_list(q);
	int n = 0;
	Pair avg = q.top();
	q.pop();
	while (!q.empty())
	{
		n++;
		avg += q.top();
		q.pop();
	}
	q = copy_list_to_queue(l);
	return avg / n;
}
pri_queue removeInrange(pri_queue q, int begin, int end)
{
	pri_queue tmp;
	Pair p;
	for (int n = 1; n <= begin; n++)
	{
		p = q.top();
		q.pop();
		tmp.push(p);
	}
	for (int n = 1; n <= end; n++)
	{
		q.pop();
	}
	for (int n = 1; n <= q.size(); n++)
	{
		p = q.top();
		q.pop();
		tmp.push(p);
	}
	return tmp;
}
ostream& operator << (ostream& out, pri_queue q)
{
	while (!q.empty())
	{
		out << q.top() << " <- ";
		q.pop();
	}
	return out;
}
pri_queue add_average(pri_queue q)
{
	q.push(average(q));
	return q;
}
pri_queue minmaxAddition(pri_queue q)
{
	list_Pair l = copy_queue_to_list(q);
	Pair min_p(1000000, 1000000);
	Pair max_p(0, 0);
	while (!l.empty())
	{
		if (l.front() > max_p) max_p = l.front();
		else if (l.front() < min_p) min_p = l.front();
		l.pop_front();
	}
	l = copy_queue_to_list(q);
	for_each(l.begin(), l.end(), [&](Pair& p) {p += min_p; p += max_p; });
	return copy_list_to_queue(l);
}
int main()
{
	setlocale(LC_ALL, "rus");
	Pair p;
	pri_queue q;
	int n;
	cout << "Укажите размер очереди: ";
	cin >> n;
	q = make_queue(n);
	cout << q << endl;
	q = add_average(q);
	cout << "Очередь после добавления среднего арифметического: ";
	cout << q << endl;
	int begin, end;
	cout << "Укажите диапазон для удаления элементов: ";
	cin >> begin;
	cin >> end;
	q = removeInrange(q, begin, end);
	cout << q << endl;
	cout << "Очередь после добавления минимального/максимального элементов к каждому: ";
	q = minmaxAddition(q);
	cout << q << endl;
	return 0;
}