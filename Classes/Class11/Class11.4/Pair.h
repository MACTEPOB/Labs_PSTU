#pragma once 
#include<iostream>
#include<ctime>
#include <random>
using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	Pair() : first(0), second(0.0) {}
	Pair(int f, double s) : first(f), second(s) {}
	Pair(const Pair& p) {
		first = p.first;
		second = p.second;
	}
	~Pair() {}
	void setFirst(int first) {
		this->first = first;
	}
	void setSecond(double second) {
		this->second = second;
	}
	int getFirst() {
		return first;
	}
	double getSecond() {
		return second;
	}
	Pair& operator= (const Pair& p) {
		this->first = p.first;
		this->second = p.second;
		return *this;
	}
	Pair& operator- (const Pair& p) {
		first -= p.first;
		second -= p.second;
		return *this;
	}
	Pair& operator/ (int c) {
		first /= c;
		second /= c;
		return *this;
	}
	Pair& operator+ (int x) {
		first += x;
		return *this;
	}
	Pair& operator+ (double x) {
		second += x;
		return *this;
	}
	bool operator > (const Pair& p) {
		if (first + second > p.first + p.second) return true;
		else return false;
	}
	bool operator < (const Pair& p) const {
		if (first + second < p.first + p.second) return true;
		else return false;
	}
	bool operator!= (Pair& p) {
		if (first != p.first && second != p.second) return true;
		else return false;
	}
	Pair& operator+ (const Pair& p) {
		first += p.first;
		second += p.second;
		return *this;
	}
	void randomize() {
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<double> dis(1.0, 10.0);
		first = rand() % 10;
		second = static_cast<int>(dis(gen) * 10) / 10.0;
	}
	Pair& operator+= (const Pair& p) {
		first += p.first;
		second += p.second;
		return *this;
	}
	friend ostream& operator<< (ostream& out, const Pair& p) {
		return (out << p.first << ":" << p.second << " ");
	}
	friend istream& operator>> (istream& in, Pair& p) {
		cout << "first?"; in >> p.first;
		cout << "second?"; in >> p.second;
		return in;
	}
};