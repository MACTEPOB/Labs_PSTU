#include <iostream>
#include "Pair.h"
#include <algorithm>
#include <queue>

typedef priority_queue<Pair> pq;

pq makeQueue(int n)
{
	Pair p;
	pq queue;
	for (auto i = 0; i < n; i++)
	{
		cin >> p;
		queue.push(p);
	}
	return queue;
}
void printQueue(pq q)
{
	pq tmp;
	while (!q.empty())
	{
		tmp.push(q.top());
		cout << q.top() << ' ';
		q.pop();
	}
	while (!tmp.empty())
	{
		q.push(tmp.top());
		tmp.pop();
	}
	cout << endl;
}
void arithmetic_mean(pq q)
{
	Pair sum;
	pq tmp;
	while (!q.empty())
	{
		sum += q.top();
		tmp.push(q.top());
		q.pop();
	}
	sum = sum / q.size();
	while (!tmp.empty())
	{
		q.push(tmp.top());
		tmp.pop();
	}
	q.push(sum);
}
void removeInrange(pq q, int begin, int end, Pair p)
{
	int i = 1;
	pq tmp;
	while (!q.empty())
	{
		if (i < begin || i > end || (p != q.top()))
			tmp.push(q.top());
		i++;
		q.pop();
	}
	while (!tmp.empty())
	{
		q.push(tmp.top());
		tmp.pop();
	}
}

void MinMax_addition(pq q)
{
	Pair max = q.top();
	Pair min = q.top();
	pq tmp;
	while (!q.empty())
	{
		tmp.push(q.top());
		if (max < q.top())
			max = q.top();
		else 
		if (min < q.top())
		{
			min = q.top();
		}
		q.pop();
	}
	Pair tmp_p;
	while (!tmp.empty())
	{
		tmp_p = tmp.top();
		tmp_p += min;
		tmp_p = max;
		q.push(tmp_p);
		tmp.pop();
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	pq q;
	std::cout << "Укажите размер контейнера: ";
	int n;
	cin >> n;
	q = makeQueue(n);
	printQueue(q);

	arithmetic_mean(q);
	cout << "Контейнер после добавления среднего арифмитического: ";
	printQueue(q);

	cout << "Укажите диапазон для удаления элементов: ";
	int begin, end; Pair p;
	cin >> begin >> end;
	cin >> p;
	removeInrange(q, begin, end, p);
	cout << "Список после удаления элементов: ";
	printQueue(q);

	MinMax_addition(q);
	cout << "Список после добавления минимального/максимального элементов к каждому: ";
	printQueue(q);
	return 0;
}