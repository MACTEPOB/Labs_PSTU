#pragma once
#include "Person.h"

class Teacher : public Person
{
protected:
	string subject;
	int hours;
public:
	Teacher()
	{
		subject = "none";
		int hours = -1;
	}
	Teacher(string sub, int hours)
	{
		this->subject = sub;
		this->hours = hours;
	}
	Teacher(const Teacher& tmp)
	{
		this->subject = tmp.fullName;
		this->hours = tmp.hours;
	}
	~Teacher() {}
	void setSubject(string sub)
	{
		subject = sub;
	}
	void setHours(int h)
	{
		hours = h;
	}
	string getSubject()
	{
		return subject;
	}
	int getHours()
	{
		return hours;
	}
	friend istream& operator>>(istream& in, Teacher& s)
	{
		cout << "Name? "; cin >> s.fullName;
		cout << "Age? "; cin >> s.age;
		cout << "Subject? "; cin >> s.subject;
		cout << "Hours? "; cin >> s.hours;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Teacher& s)
	{
		out << "Name:" << s.fullName << endl;
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