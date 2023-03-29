#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void c8to10(int num, int first, ...)
{
    int* ptr = &first;
    while (num >= 1)
    {
        int st = 0;
        double res = 0;
        int k = *ptr;
        while (k > 0)
        {
            res += (k % 10) * pow(8, st);
            k /= 10;
            st += 1;
        }
        
        cout << res << " ";
        num = num - 1;
        ptr++;
    }
}
int main()
{
    c8to10(3, 72, 12, 24);
    cout << endl;
    c8to10(6, 131, 232, 343, 454, 565, 676);
    cout << endl;
    c8to10(7, 777, 666, 727, 1327, 1337, 227, 1477);
    return 0;
}
