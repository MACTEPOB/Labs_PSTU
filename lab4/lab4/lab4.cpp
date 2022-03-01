#include <iostream>
using namespace std;

int main()
{
    int n = 14;
    int a[100], b[100];
    srand(time(NULL));
    cout << "Default secuence: ";
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 101;
        cout << " " << a[i];
    }
    cout << endl;
    if (n % 2 != 0)
    {
        for (int i = n / 2 + 1; i < n; ++i)
            a[i] = a[i + 1];
        --n;
    }
    for (int i = 0; i < (n / 2);i++)
        swap(a[i], a[n - i - 1]);
    cout << "Processed secuence:";
    
    for (int i = 0; i < 3; i++)
        b[i] =  a[i + 10] - 2;
    for (int i = 0; i < n; i++)
    {
        b[i+3] = a[i];
    }
    for (int i = 0; i < n + 3; i++)
        cout << " " << b[i];
    return 0;
}
