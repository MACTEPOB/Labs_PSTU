#include <iostream>
#include <windows.h>
#include "car.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Car car1("Toyota", "Celica", 1200000);
	car1.show();
	Car car2;
	car2.setBrand();
	car2.setModel();
	car2.setPrice();
	car2.show();
	return 0;
}