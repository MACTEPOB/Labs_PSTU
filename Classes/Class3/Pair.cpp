#include<iostream>
#include "Pair.h"
using namespace std;

Pair::Pair()
{
	first = 0;
	second = 0.0;
}

Pair::Pair(int f, double s)
{
	first = f;
	second = s;
}

Pair::Pair(const Pair& other)
{
	first = other.first;
	second = other.second;
}

Pair:: ~Pair() {}

int Pair::getFirst()
{
	return first;
}

double Pair::getSecond()
{
	return second;
}

void Pair::setFirst(int f)
{
	first = f;
}

void Pair::setSecond(double s)
{
	second = s;
}

Pair& Pair::operator=(const Pair& other) 
{
	if (this != &other) {
		first = other.first;
		second = other.second;
	}
	return *this;
}

ostream& operator<<(ostream& os, Pair& pair) 
{
	os << pair.first << ":" << pair.second;
	return os;
}

istream& operator>>(istream& is, Pair& pair) 
{
	is >> pair.first >> pair.second;
	return is;
}

bool Pair::operator==(const Pair& other) 
{
	return first == other.first && second == other.second;
}

bool Pair::operator!=(const Pair& other) 
{
	return !(*this == other);
}

void Pair::operator-(int constant) {
	first -= constant;
}

void Pair::operator-(double constant) {
	second -= constant;
}