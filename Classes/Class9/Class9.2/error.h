#pragma once
#include<string>
using namespace std;
class error
{
private:
	string msg;
public:
	error(string msg)
	{
		this->msg = msg;
	}
	void what()
	{
		cout << "Произошла ошибка: " << msg << endl;
	}
};