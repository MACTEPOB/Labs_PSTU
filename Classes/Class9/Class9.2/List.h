#pragma once
#include "error.h"
using namespace std;
int max_size = 6;

class List
{
private:
	int size;
	int* array;
public:
	List()
	{
		size = 0;
		array = 0;
	}
	List(int size)
	{
		this->size = size;
		if (size > max_size) { throw error("Недопустимый размер множества!"); }
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 100 + 1;
		}

	}
	List(int size, int* array)
	{
		this->size = size;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->array[i] = array[i];
		}


	}
	List(const List& other)
	{
		this->size = other.size;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}
	~List()
	{
	}
	void show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
	int& operator () () { return size; }
	List operator - (const List& other)
	{
		List tmp(size);
		for (int i = 0; i < size; i++)
		{
			tmp.array[i] = array[i] - other.array[i];
		}
		delete[]array;
		return tmp;
	}
	int& operator [](int index)
	{

		if (index >= 0 && index < size)
		{
			return array[index];
		}
		else
		{
			cout << endl;
			throw error("Недопустимый индекс");
		}
	}
	List operator --()
	{
		if (size == 0) { throw error("Невозможно удалить элемент, размер множества равен 0"); }
		if (size == 1)
		{
			size = 0;
			delete[]array;
			array = 0;
			return*this;
		}
		int tmp_size = size--;
		List tmp(tmp_size);
		for (int i = 0; i < tmp_size; i++)
		{
			tmp.array[i] = 0;
		}
		for (int i = 0; i < tmp_size; i++)
		{
			tmp.array[i] = array[i];
		}
		return tmp;
		delete[]array;
	}


};