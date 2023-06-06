#include <set>
#include <algorithm>
#include <iostream>
#include "Set.h"
#include "Pair.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Set<Pair> set;
	cout << "Укажите размер: ";
	int n;
	cin >> n;
	set.make_set(n);
	set.print_set();

	return 0;
}