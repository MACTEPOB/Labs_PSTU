#pragma once 
#include <iostream>
using namespace std;

class Pair {
private:
    int first;
    double second;

public:
    Pair();
    Pair(int f, double s);
    Pair(const Pair& other);
    ~Pair();
    int getFirst();
    double getSecond();
    void setFirst(int f);
    void setSecond(double s);
    Pair& operator=(const Pair& other);
    friend ostream& operator<<(ostream& os, Pair& pair);
    friend istream& operator>>(istream& is, Pair& pair);
    bool operator==(const Pair& other);
    bool operator!=(const Pair& other);
    // ѕерегрузка операции вычитани€ константы из пары
    void operator-(int constant);
    void operator-(double constant);
};