#include <iostream>
#include <ctime>
using namespace std;

int linSearch(int arr[], int key, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	srand(time(NULL));
	int size, key;
	cout << "Enter no of elements: ";
	cin >> size;
	int* arr = new int[size];
	cout << "Random array:";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101;
		cout << " " << arr[i];
	}
	cout << "\nEnter the value of element u wanna find: ";
	cin >> key;
	if (linSearch(arr, key, size) == -1)
	{
		cout << "I can'f find ur element";
	}
	else
	{
		cout << "No of ur number is: " << linSearch(arr, key, size) + 1;
	}
	delete[] arr;
	return 0;
}