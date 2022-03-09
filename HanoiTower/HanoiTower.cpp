#include <iostream>
using namespace std;
void hanoi(int num, char from, char to, char buff)
{
    if (num != 0)
    {
        hanoi(num - 1, from, buff, to);
        cout << from << " -> " << to << endl;
        hanoi(num - 1, buff, to, from);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int num;
    cout << "Введите количество колец: ";
    cin >> num;
    cout << endl;
    hanoi(num, '1', '2', '3');
    return 0;
}
