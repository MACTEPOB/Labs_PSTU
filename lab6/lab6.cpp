#include <iostream>
#include <string>
using namespace std;

void sort(string s)
{
	for (int i = 0; i < s.length() - 1; i++)
		for (int j = i + 1; j < s.length(); j++)
			if ((s[i] >= '0') and (s[i] <= '9') and (s[j] >= '0') and (s[j] <= '9') and (s[i] < s[j]))
				swap(s[i], s[j]);
	cout << s;
}

int main()
{
	string s = "", w = "";
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			sort(w);
			w = "";
			cout << " ";
		}
		else
			w += s[i];
		if (i == s.length() - 1)
			sort(w);
	}
	return 0;
}