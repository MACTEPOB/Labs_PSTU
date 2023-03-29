#include <iostream>
using namespace std;

int hmm(int h, int min)
{
    int answ;
    answ = h * 60 + min;
    return answ;
}

void mhm(int min)
{
    int answ1, answ2;
    answ1 = min / 60;
    answ2 = min % 60;
    cout << answ1 << ":" << answ2;
}

int main()
{
    cout << hmm(5, 25) << endl;
    void(mhm(370));
    return 0;
}