#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    const int n = 10;
    int a[n];
    srand(time(NULL));
    cout << "Default sequence:";
    for (int i = 0; i <= 9; i++)
    {
        a[i] = rand() % 101;
        cout << " " << a[i];
    }
    cout << endl;
    int p, q;
    cout << "Задайте индексы p и q\n";
    cin >> p >> q;
    while (p != q && p<q)
    {
        swap(a[p], a[q]);
        p++;
        q--;
    }
    cout << "Reversed sequence:";
    for (int i = 0; i <= 9; i++)
    {
        cout << " " << a[i];
    }
    return 0;
}