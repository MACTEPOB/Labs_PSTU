#pragma once
#include<iostream>
#include "Pair.h"
using namespace std;

template <typename T>
class List {
private:
    T* data;
    int size;

public:
    List() : data(nullptr), size(0) {}

    List(int s) : size(s) {
        data = new T[size];
    }

    List(const List& other) : size(other.size) {
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~List() {
        delete[] data;
    }

    int operator()() const {
        return size;
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    List& operator=(const List& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const List& list) {
        for (int i = 0; i < list.size; i++) {
            os << list.data[i] << " ";
        }
        return os;
    }

    friend istream& operator>>(istream& is, List& list) {
        delete[] list.data;
        is >> list.size;
        list.data = new T[list.size];
        for (int i = 0; i < list.size; i++) {
            is >> list.data[i];
        }
        return is;
    }

    List operator*(int num) const {
        List result(*this);
        for (int i = 0; i < size; i++) {
            result.data[i] = result.data[i] * num;
        }
        return result;
    }
};