#include<iostream>
#include "vector.h"
#include "Teacher.h"
using namespace std;

int main()
{
	Vector v(5);

	Person p;
	cin >> p;
	Teacher s;
	cin >> s;
	s.increaseHours(5);
	s.decreaseHours(10);
	Object* ptr = &p;
	v.Add(ptr);
	ptr = &s;
	v.Add(ptr);
	cout << v;

	return 0;
}
