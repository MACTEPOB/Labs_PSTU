#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream f1("F1.txt");
	f1 << "A B C\nA B B C\nB B C\nA A B B C\nB B C\nB B C\nA B B D\nA B B C\nA B B C\nC B B A\n";
	f1.close();
	ifstream f1_in("F1.txt");
	ofstream f2("F2.txt");
	int n1, n2;
	cout << "Задайте номера строк N1 и N2\n";
	cin >> n1 >> n2;
	int n = 0;
	string line;
	while (getline(f1_in, line))
	{
		n++;
		if (n >= n1 && n <= n2 && line[0] == 'A' && line[line.length() - 1] == 'C')
		{
			f2 << line << endl;
		}
	}
	f1_in.close();
	f2.close();
	ifstream f2_in("F2.txt");
	if (getline(f2_in, line))
	{
		int count = 0;
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ' ')
			{
				count++;
			}
		}
		cout << "Кол-во слов в первой строке файла F2: " << count << ".\n";
	}
	else
	{
		cout << "Файл F2 пуст.\n";
	}
	f2_in.close();
	return 0;
}