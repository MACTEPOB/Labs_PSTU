#pragma once
#include <iostream>
#include "Print.h"
using namespace std;

class BOOK : public PRINT {
private:
    int pageCount;
    string publisher;

public:
    void input() override {
        cout << "Enter the title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter the author: ";
        getline(cin, author);
        cout << "Enter the page count: ";
        cin >> pageCount;
        cin.ignore();
        cout << "Enter the publisher: ";
        getline(cin, publisher);
    }

    void output() const override {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Page count: " << pageCount << endl;
        cout << "Publisher: " << publisher << endl << endl;
    }
};