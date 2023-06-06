#pragma once
#include <set>
#include <algorithm>
#include <iostream>
#include "Pair.h"
using namespace std;

template <typename T>
class Set
{
private:
	int size = 0;
	multiset<T> set;
public:
	Set() { size = set.size(); }
	/*int size() { return size; }*/
	void make_set(int n) {
		for (int i = 0; i < n; i++)
		{
			T data;
			data.randomize();
			set.insert(data);
		}
	}
	void print_set() {
		for (auto& i : set)
		{
			cout << i << ' ';
		}
		cout << endl;
	}
	void average() {
		T avrg;
		for (auto& i : set)
		{
			avrg = avrg + i;
		}
		set.insert(avrg);
		size++;
	}
	void removeInrange(T begin, T end) {
		auto left = set.lower_bound(begin);
		auto right = set.upper_bound(end);
		set.erase(left, right);
		size = set.size();
	}
	void min_max_addition() {
		multiset<T> tmp;
		T min = *set.begin(), max = *set.end();
		for (auto& i : set)
		{
			if (i < min)
			{
				min = i;
			}
			else if (i > max)
			{
				max = i;
			}
		}
		for (auto& i : set)
		{
			tmp.insert(i + min + max);
		}
		tmp.swap(set);
	}
};

