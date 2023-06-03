#pragma once
#include <iostream>
using namespace std;

class Pair {
private:
    int first;
public:
    double second;
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}

    bool operator==(const Pair& other) const {
        return (first == other.first && second == other.second);
    }

    bool operator!=(const Pair& other) const {
        return !(*this == other);
    }

    Pair operator*(double value) const {
        return Pair(first * value, second * value);
    }

    friend ostream& operator<<(ostream& os, const Pair& pair) {
        os << pair.first << ":" << pair.second;
        return os;
    }

    friend istream& operator>>(istream& is, Pair& pair) {
        char colon;
        is >> pair.first >> colon >> pair.second;
        return is;
    }

    bool operator<(const Pair& other) const {
        return (first < other.first);
    }
    bool operator>(const Pair& other) const {
        return (first > other.first);
    }
};
