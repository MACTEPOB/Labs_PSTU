
#include <iostream>
#include <cstdlib> 
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	const int n = 5;
	int a[n][n], b[n-1], s = n, tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 89 + 11;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i = 0; i < n-1; i++)
	{
		b[i] = 0;
		s--;
		for (int j = 0; j < s; j++)
		{
			b[i] += a[j][i];
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (b[i] > s)
		{
			s = b[i];
		}
	}
	cout << "\nÍàèáîëüøàÿ ñóììà - " << s;
}
