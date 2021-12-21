#include <iostream>
using namespace std;
int main()
{
    int x = 1, a = 1, b = 1, c = 1;
    while ((a == b) or (b == c) or (a == c) or (x < 100) or (x > 999))
    {
        cout << "Введите трехзначное число, в котором все цифры различны" << endl;
        cin >> x;
        if ((x>=100) and (x<=999))
        {
            a = x % 10;
            b = (x / 10) % 10;
            c = x / 100;
        }
        if ((a == b) or (b == c) or (a == c) or (x < 100) or (x > 999))
            cout << "Вы ввели число, не удовлетворяющее условиям" << endl; 
    }
    cout << "Все возможные комбинации цифр" << endl;
    if (a != 0)
    {    
        cout << a << b << c << endl;
        cout << a << c << b << endl;
    }
    if (b != 0)
    {
        cout << b << a << c << endl;
        cout << b << c << a << endl;
    }
    if (c != 0)
    {    
        cout << c << a << b << endl;
        cout << c << b << a << endl;
    }
    cout << "Наибольшее число из данных цифр - ";
    if ((a>b) and (a>c))
        if (b>c)
            cout << a*100+10*b+c;
        else
            cout << 100*a+10*c+b;
    if ((b>a) and (b>c))
        if (a>c)
            cout << 100*b+10*a+c;
        else
            cout << 100*b+10*c+a;
    if ((c>a) and (c>b))
        if (a>b)
            cout << 100*c+10*a+b;
        else
            cout << 100*c+10*b+a;
    return 0;
}
