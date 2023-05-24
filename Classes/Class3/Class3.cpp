#include <iostream>
#include "Pair.h"
using namespace std;

int main() {
    Pair pair1(5, 3.5);
    Pair pair2;

    cout << "pair1: " << pair1 << endl;

    cout << "Enter a pair (int double): ";
    cin >> pair2;
    cout << "pair2: " << pair2 << endl;
    if (pair1 == pair2) 
    {
        cout << "pair1 = pair2" << endl;
    }
    else 
    {
        cout << "pair1 != pair2" << endl;
    }

    pair1 - 2;
    cout << "pair1 - 2: " << pair1 << endl;

    pair2 - 1.1;
    cout << "pair2 - 1.1: " << pair2 << endl;

    return 0;
}