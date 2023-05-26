#pragma once
#include <string>
using namespace std;

class PRINT {
protected:
    string title;
    string author;

public:
    virtual void input() = 0;
    virtual void output() const = 0;
};
