#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int tmp=0;
    int a[n];
    srand(time(NULL));
    cout << "Default sequence:";
    for (int i = 0; i <= 9; i++)
    {
        a[i] = rand() % 101;
        cout << " " << a[i];
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }

        }
    }
    cout << "Increasing sequence:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}
