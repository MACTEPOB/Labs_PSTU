#include <iostream>
using namespace std;

void hoare(int* a, int first, int last)
{
	int f = first;
	int l = last;
	double tmp, x = a[(first + last) / 2];
	do {
		while (a[f] < x)
			f++;
		while (a[l] > x)
			l--;

		if (f <= l)
		{
			if (f < l)
			{
				swap(a[f], a[l]);
			}
			f++;
			l--;
		}
	} while (f <= l);

	if (f < last)
		hoare(a, f, last);
	if (first < l)
		hoare(a, first, l);
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, d, j, g, c, nf = 0;
	srand(time(NULL));
	cout << "Задайте размер массива" << endl;
	cin >> n;
	int nl = n - 1;
	int* a = new int[n];
	cout << "Default sequence:";
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		cout << " " << a[i];
	}
	cout << endl;
	hoare(a, nf, nl);
	cout << "Sorted sequence:";
	for (int i = 0; i < n; i++)
		cout << " " << a[i];
	return 0;
}