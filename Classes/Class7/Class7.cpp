#include <iostream>
#include "List.h"
using namespace std;


int main() {
    List<Pair> pairList;
    cout << "Enter the size and elements of the pair list (format: first:second): ";
    cin >> pairList;
    cout << "Pair List: " << pairList << endl;
    int num;
    cout << "Enter num for multiplying: ";
    cin >> num;
    List<Pair> multipliedList = pairList * num;
    cout << "Multiplied int List: " << multipliedList << endl;
    return 0;
}