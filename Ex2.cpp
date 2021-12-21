#include <iostream>
using namespace std;
int main()
{
    int a, x, k = 0;
    srand(time(NULL));
    x = rand() % 100 + 1;
    cout << "Вам необходимо угадать число в промежутке от 1 до 100 за 5 попыток." << endl;
    cout << "Введите число от 1 до 100." << endl;
    for (int i = 1; i <= 5; i++)
    {
        cin >> a;
        if (x == a)
        {
            cout << "Поздравляю, вы угадали число.";
            return 0;
        }
        else
        {
            if (a > x) 
                cout << "Загаданное число меньше вашего. Попробуйте еще раз." << endl;
            else 
                cout << "Загаданное число больше вашего. Попробуйте еще раз." << endl;
        }
        k += 1;
    }
    if ((k == 5) and (x != a))
        cout << "Вы не угадали число, попытки закончились. Загаданное число - " << x;
    return 0;
}
