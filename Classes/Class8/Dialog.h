#pragma once
#include <string>
#include "Tree.h"

class Dialog : public Tree {
public:
    void handleEvents() {
        string command;
        bool quit = false;

        while (!quit) {
            cout << "Menu:\nCreate group(m)\nAdd element(+)\nDelete element(-)\nShow group(s)\nShow info about an element(z)\nQuit(q)\n\n";
            cin >> command;
            cout << endl;
            if (command == "m") {
                int count;
                cout << "Enter the number of elements to create: ";
                cin >> count;
                createElements(count);
            }
            else if (command == "+") {
                PRINT* newElement = createElement();
                if (newElement != nullptr) {
                    addElement(newElement);
                }
            }
            else if (command == "-") {
                int index;
                cout << "Enter the index of the element to remove: ";
                cin >> index;
                removeElement(index);
            }
            else if (command == "s") {
                printElements();
            }
            else if (command == "z") {
                int index;
                cout << "Enter the index of the element: ";
                cin >> index;
                PRINT* element = getElement(index);
                if (element != nullptr) {
                    element->output();
                }
            }
            else if (command == "q") {
                quit = true;
            }
            else {
                cout << "Invalid command!" << endl;
            }
        }
    }

private:
    void createElements(int count) {
        for (int i = 0; i < count; i++) {
            PRINT* newElement = createElement();
            if (newElement != nullptr) {
                addElement(newElement);
            }
        }
    }

    PRINT* createElement() {
        PRINT* newElement = new BOOK();
        newElement->input();
        return newElement;
    }
};
