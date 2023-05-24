#pragma once
#include <string>
using namespace std;

class Car
{
	string Brand;
	string Model;
	int Price;
public:
	Car();
	Car(string brand, string model, int price);
	~Car();
	void show();
	string getBrand();
	string getModel();
	int getPrice();
	void setBrand();
	void setModel();
	void setPrice();
};
