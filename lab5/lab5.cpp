#include <iostream>
#include <cstdlib> 
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int n = 5;
	int a[n][n], max, proizv = 1;
	bool flag = false;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 9 + 1;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	max = a[0][0];
	for (int i = 1; i < n; i++)
		if (a[i][i] > max)
			max = a[i][i];
	int j = n-1;
	for (int i = 0; i < n; i++, j--)
		if (a[i][j] > max)
			max = a[i][j];
	cout << "Наибольший элемент главной и побочной диагоналей: " << max << endl;
	for (int i = 0; i < n; i++)
		if (a[0][i] > max)
		{
			flag = true;
			cout << "Произведение элементов " << i + 1 << " столбца: ";
			for (int j = 0; j < n; j++)
				proizv *= a[j][i];
			cout << proizv << endl;
			proizv = 1;
		}
	if (not flag)
		cout << "В данном массиве отсутствуют столбцы, в которых первый элемент больше наибольшего элемента диагоналей" << endl;
	return 0;
}