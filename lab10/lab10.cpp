#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Задайте количество строк массива\n";
	cin >> n;
	string* arr = new string[n];
	cout << "Заполните строки массива\n";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int min = arr[0].length();
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].length() < min)
		{
			min = arr[i].length();
			k = i;
		}
	}
	for (int i = k; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	cout << "Результат:\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr;
	return 0;
}