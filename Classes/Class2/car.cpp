#include <iostream>
#include <string>
#include "car.h"

using namespace std;

Car::Car()
{
	Brand = " ";
	Model = " ";
	Price = 0;
}

Car::Car(string brand, string model, int price)
{
	Brand = brand;
	Model = model;
	Price = price;
}

/*Car::~Car()
{
	cout << "Îøèáêà\n";
}*/

void Car::show()
{
	cout << "Car: " << Brand << " " << Model << "\nPrice: " << Price << endl;
}

string Car::getBrand()
{
	return Brand;
}

string Car::getModel()
{
	return Model;
}

int Car::getPrice()
{
	return Price;
}

void Car::setBrand()
{
	string brand;
	cout << "Enter car brand: ";
	cin >> brand;
	Brand = brand;
}

void Car::setModel()
{
	string model;
	cout << "Enter car model: ";
	cin >> model;
	Model = model;
}

void Car::setPrice()
{
	int price;
	cout << "Enter car price: ";
	cin >> price;
	Price = price;
}