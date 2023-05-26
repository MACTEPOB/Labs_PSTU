#pragma once
#include <iostream>
using namespace std;

class Pair {
private:
    int first;
    double second;

public:
    Pair() : first(0), second(0) {}
    Pair(int f, double s) : first(f), second(s) {}
    ~Pair() {}

    friend ostream& operator<<(ostream& os, const Pair& p) {
        os << p.first << ":" << p.second;
        return os;
    }

    friend istream& operator>>(istream& is, Pair& p) {
        is >> p.first >> p.second;
        return is;
    }

    Pair operator*(int num) const {
        return Pair(first * num, second * num);
    }
};
