#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void c2to3(int num, int first, ...)
{
    int* ptr = &first;
    while (num >= 1)
    {
        int c = 0, as, st = 0;
        int k = *ptr;
        string j = "";
        while (k > 0)
        {
            c = c + (k % 10) * pow(2, st);
            k /= 10;
            st += 1;
        }
        while (c > 0)
        {
            k = c % 3;
            j = to_string(k) + j;
            c = c / 3;
        }
        cout << j << " ";
        num = num - 1;
        ptr++;
    }
}
int main()
{
    c2to3(3, 10000, 10001, 10010);
    cout << endl;
    c2to3(6, 10011, 10100, 10101, 10110, 10111, 11000);
    cout << endl;
    c2to3(7, 11001, 11010, 11011, 11100, 11101, 11110, 11111);
    return 0;
}