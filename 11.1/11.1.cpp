#include <iostream>
using namespace std;

struct Node
{
	char data;
	Node* next;
};

Node* createlist(int n)
{
	Node* first;
	Node* p, * r;
	first = new(Node);
	cout << "\n -> ";
	cin >> first->data;
	first->next = 0;
	p = first;
	for (int i = 0; i < n - 1; i++)
	{
		r = new(Node);
		cout << "\n -> ";
		cin >> r->data;
		r->next = 0;
		p->next = r;
		p = r;

	}
	return first;
}

void print_list(Node* first)
{
	Node* p = first;
	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;
	}
}

Node* add_element(Node* first, int n, char b, char c)
{
	Node* p = first;
	Node* New = new(Node);
	cout << "Задайте добавляемый элемент -> ";
	New->data = c;
	for (int i = 0; i < n && p != 0; i++)
	{
		if (p != nullptr && p->data == b)
		{
			New->next = p->next;
			p->next = New;
		}
		p = p->next;
	}
	return first;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Задайте размер списка -> ";
	cin >> n;
	char b, c;
	cout << "Задайте элемент и номер, под которым его необходимо добавить -> ";
	cin >> c >> b;
	Node* first = createlist(n);
	add_element(first, n, b, c);
	print_list(first);
	return 0;
}