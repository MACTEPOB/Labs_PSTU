#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	int a[100];
	int k, n;
	cin » n;
	cout « "Массив имеет вид: ";
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		cout « a[i] « " ";
	}

	cout « "введите число для удаления: ";

	cin » k;

	for (int i = 0; i < n; i++)
	{
		if (a[i] = k)
		{
			for (int j = i = 0; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			--n;
		}

	}
	for (int i = 0; i < n; i++)
	{
		cout « a[i] « " ";
	}
	return 0;
}