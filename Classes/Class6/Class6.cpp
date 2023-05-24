#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List list;
    int i, b;
    cout << "Menu:\nAdd elem(1)\nPrint list(2)\nFind element(3)\nFind size(4)\nMultiplication by a number(5)\nClear list(6)\nExit(0)\n";
    do
    {
        cin >> i;
        switch (i)
        {
        case 1:
            cout << "Enter num: ";
            cin >> b;
            list.push_back(b);
            break;
        case 2:
            list.show(list);
            break;
        case 3:
            cout << "Enter index: ";
            cin >> b;
            cout << "Element at index " << b << ": " << list[b] << endl;
            break;
        case 4:
            cout << "Size of list: " << list() << endl;
            break;
        case 5:
            cout << "Enter num for multiplicating: ";
            cin >> b;
            list * b;
            list.show(list);
            break;
        case 6:
            cout << "Cleared\n";
            list.clear();
            break;
        case 0:
            break;
        default:
            cout << "You picked the wrong number\n";
            break;
        }
    } while (i != 0);
    return 0;
}