#pragma once
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Teacher : public Person {
protected:
    string subject;
    int hours;
public:
    Teacher() : Person(), subject(""), hours(0) {}

    Teacher(const std::string& n, int a, const std::string& s, int h) : Person(n, a), subject(s), hours(h) {}

    Teacher(const Teacher& other) : Person(other), subject(other.subject), hours(other.hours) {}

    ~Teacher() {}

    string getSubject() const {
        return subject;
    }

    int getHours() const {
        return hours;
    }

    void setSubject(const string& s) {
        subject = s;
    }

    void setHours(int h) {
        hours = h;
    }

    friend istream& operator>>(istream& in, Teacher& s)
    {
        cout << "Name? "; cin >> s.name;
        cout << "Age? "; cin >> s.age;
        cout << "Subject? "; cin >> s.subject;
        cout << "Hours? "; cin >> s.hours;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Teacher& s)
    {
        out << "\nName:" << s.name << endl;
        out << "Age: " << s.age << endl;
        out << "Subject: " << s.subject << endl;
        out << "Hours: " << s.hours << endl;
        return out;

    }
    void increaseHours(int amount) {
        hours += amount;
    }

    void decreaseHours(int amount) {
        hours -= amount;
        if (hours < 0) {
            hours = 0;
        }
    }
};
