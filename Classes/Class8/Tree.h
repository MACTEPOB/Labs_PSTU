#include "Book.h"
#include <vector>
#pragma once

class Tree {
private:
    vector<PRINT*> elements;

public:
    void addElement(PRINT* element) {
        elements.push_back(element);
    }

    void removeElement(int index) {
        if (index >= 0 && index < elements.size()) {
            delete elements[index];
            elements.erase(elements.begin() + index);
        }
    }

    void printElements() const {
        for (const PRINT* element : elements) {
            element->output();
            cout << endl;
        }
    }

    PRINT* getElement(int index) const {
        if (index >= 0 && index < elements.size()) {
            return elements[index];
        }
        return nullptr;
    }

    int getSize() const {
        return elements.size();
    }

    ~Tree() {
        for (PRINT* element : elements) {
            delete element;
        }
    }
};