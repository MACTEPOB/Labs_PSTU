#include <iostream>
#include <fstream>
#include "file_work.h"
using namespace std;

int main() {
    string filename = "pairs.txt";
    int choice;
    Pair k1, k2, value;
    int K;
    cout << "Menu\n";
    cout << "1. Create objects and save to file.\n";
    cout << "2. Read and display objects from file.\n";
    cout << "3. Delete objects from file within a range.\n";
    cout << "4. Double objects with a specified value.\n";
    cout << "5. Add objects to the beginning of the file.\n";
    cout << "0. Exit.\n";
    do {
        
        cin >> choice;

        switch (choice) {
        case 1:
            createFile(filename);
            break;
        case 2:
            showFile(filename);
            break;
        case 3:
            cout << "Enter k1 (format: first:second): ";
            cin >> k1;
            cout << "Enter k2 (format: first:second): ";
            cin >> k2;
            deleteObjects(filename, k1, k2);
            break;
        case 4:
            cout << "Enter the value to double (format: first:second): ";
            cin >> value;
            doubleObjects(filename, value);
            break;
        case 5:
            cout << "Enter the number of objects to add at the beginning: ";
            cin >> K;
            addObjects(filename, K);
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}