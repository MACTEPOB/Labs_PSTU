#include <iostream>
#include <cmath>
using namespace std;

double logarifm(double n)
{
    double lg = 0;
    lg = log(n);
    return lg;
}

double logarifm(int n)
{
    double lg = 0;
    lg = log10(n);
    return lg;
}

int main()
{
    cout << logarifm(5.25) << endl;
    cout << logarifm(1000);
    return 0;
}
