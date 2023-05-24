#include <iostream>
#include <string>
#include "Teacher.h"

using namespace std;


int main() {
    
    Teacher teacher1;
    cin >> teacher1;
    cout << teacher1 << endl;

    teacher1.increaseHours(5);
    cout << "(after increase): " << teacher1 << endl;

    teacher1.decreaseHours(10);
    cout << "(after decrease): " << teacher1 << endl;

    return 0;
}
