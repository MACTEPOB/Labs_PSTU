#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person()
    {
        name = "";
        age = 0;
    }
    Person(const string& n, int a) 
    {
        name = n;
        age = a;
    }

    Person(const Person& other) 
    {
        name = other.name;
        age = other.age;
    }

    ~Person() {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void setName(const string& n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Age: " << person.age;
        return os;
    }

    friend istream& operator>>(istream& is, Person& person) {
        cout << "Enter name: ";
        is >> person.name;
        cout << "Enter age: ";
        is >> person.age;
        return is;
    }
};

Person getPerson(const Person& person) {
    return person;
}
