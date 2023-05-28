#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string get_random_fio();
string get_random_phone();
string get_random_date();
int get_random_number();
int sum_date(string str);

struct Human
{
	Human()
	{
		fio = "NULL";
		phone = "NULL";
		date = "NULL";
	}
	string fio;
	string phone;
	string date;
};

struct hash_table
{
	Human* arr;
	hash_table(int size)
	{
		arr = new Human[size];
	}
	void add(Human tmp, int size);
	void pop(string delete_date, int size);
	void search_index(string date, int size);
};

string names[25] = { "Александр", "Максим", "Дмитрий", "Иван", "Артем", "Николай", "Алексей", "Кирилл", "Андрей", "Сергей", "Михаил", "Владимир", "Антон", "Егор", "Анатолий", "Арсений", "Виктор", "Глеб", "Даниил", "Евгений", "Игорь", "Леонид", "Олег", "Павел", "Роман" };
string surnames[25] = { "Иванов", "Смирнов", "Кузнецов", "Попов", "Соколов", "Лебедев", "Козлов", "Новиков", "Морозов", "Петров", "Волков", "Соловьев", "Васильев", "Зайцев", "Павлов", "Семенов", "Голубев", "Виноградов", "Богданов", "Воробьев", "Федоров", "Михайлов", "Беляев", "Титов", "Кудрявцев" };
string patronymic[25] = { "Сергеевич", "Иванович", "Дмитриевич", "Николаевич", "Анатольевич", "Михайлович", "Петрович", "Владимирович", "Артурович", "Геннадьевич", "Андреевич", "Васильевич", "Аркадьевич", "Юрьевич", "Олегович", "Евгеньевич", "Викторович", "Станиславович", "Федорович", "Борисович", "Григорьевич", "Ярославович", "Романович", "Валерьевич", "Павлович" };
string phones[25] = { "+79217650894", "+79632048502", "+79145720983", "+79851037625", "+79793568210", "+79468102539", "+79382691475", "+79549173028", "+79905731624", "+79683041975", "+79164387250", "+79256019348", "+79724986031", "+79084957263", "+79831490625", "+79492630781", "+79379526810", "+79580691742", "+79925530148", "+79668249075", "+79143185760", "+79291350624", "+79742916580", "+79084527319", "+79831950672" };
string dates[25] = { "03.01.1951", "07.05.1952", "12.08.1955", "23.02.1956", "09.06.1956", "22.07.1956", "06.12.1956", "10.03.1957", "04.05.1958", "14.09.1958", "29.10.1960", "13.07.1962", "24.07.1963", "02.04.1964", "19.02.1965", "21.03.1967", "22.03.1970", "28.07.1970", "03.02.1971", "11.12.1972", "23.03.1976", "29.04.1977", "16.10.1980", "18.09.1995", "04.08.2000" };
int collision_count = 0;

string get_random_fio()
{
	return (surnames[get_random_number()] + ' ' + names[get_random_number()] + ' ' + patronymic[get_random_number()]);
}

string get_random_phone()
{
	return phones[get_random_number()];
}

string get_random_date()
{
	return dates[get_random_number()];
}

int get_random_number()
{
	return rand() % 9;
}

Human create_random_human()
{
	Human tmp;
	tmp.fio = get_random_fio();
	tmp.phone = get_random_phone();
	tmp.date = get_random_date();
	return tmp;
}

void fill_arr_of_random_humans(Human* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = create_random_human();
	}
}

int hash_function(string str, int size)
{
	double f = 0.1337 * sum_date(str);
	double g = (f - int(f)) * size;
	return int(g);
}

void hash_table::add(Human tmp, int size)
{
	int idx = hash_function(tmp.date, size);
	int hash = idx;
	if (arr[idx].fio == "NULL")
	{
		arr[idx] = tmp;
		return;
	}
	else
	{
		while (idx < size)
		{
			if (arr[idx].fio == "NULL")
			{
				arr[idx] = tmp;
				return;
			}
			idx++;
			collision_count++;
		}
		if (idx >= size)
		{
			idx = 0;
			collision_count++;
			while (idx < hash)
			{
				if (arr[idx].fio == "NULL")
				{
					arr[idx] = tmp;
					return;
				}
				idx++;
				collision_count++;
			}
		}
	}
}

void hash_table::pop(string delete_date, int size)
{
	int idx = hash_function(delete_date, size);
	int hash = idx;
	if (arr[idx].date == delete_date)
	{
		arr[idx] = Human();
		return;
	}
	else
	{
		while (idx < size)
		{
			if (arr[idx].date == delete_date)
			{
				arr[idx] = Human();
				return;
			}
			idx++;
		}
		if (idx >= size)
		{
			idx = 0;
			while (idx < hash)
			{
				if (arr[idx].date == delete_date)
				{
					arr[idx] = Human();
					return;
				}
				idx++;
			}
		}
	}
}

void hash_table::search_index(string date, int size)
{
	int idx = hash_function(date, size);
	int hash = idx;
	while (arr[idx].date != date && idx < size)
	{
		idx++;
	}
	if (idx >= size)
	{
		idx = 0;
		while (arr[idx].date != date && idx < hash)
		{
			idx++;
		}
		if (idx >= hash)
		{
			cout << "Человека с данной датой рождения (" << date << ") нет. " << endl << endl;
		}
	}
	else
	{
		cout << "Такой человек есть по индексу: " << idx << endl << endl;
	}
}

void show(Human tmp)
{
	cout << "ФИО: " << tmp.fio << endl;
	cout << "Номер телефона: " << tmp.phone << endl;
	cout << "Дата рождения: " << tmp.date << endl << endl;
}

void print_arr_of_humans(Human* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		show(arr[i]);
	}
}

void show_hash_table(hash_table* table, int size)
{
	for (int i = 0; i < size; i++)
	{
		show(table->arr[i]);
	}
}

int sum_date(string str)
{
	return stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
}

int	main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int size;
	cout << "Укажите размер хэш-таблицы: ";
	cin >> size;
	cout << endl;
	Human* arr = new Human[size];
	hash_table table(size);
	fill_arr_of_random_humans(arr, size);
	for (int i = 0; i < size; i++)
	{
		table.add(arr[i], size);
	}
	show_hash_table(&table, size);
	string date;
	cout << "Введите дату рождения для поиска человека: ";
	cin >> date;
	cout << endl;
	table.search_index(date, size);
	cout << "Введите дату рождения человека, которого хотите исключить из списка: ";
	cin >> date;
	table.pop(date, size);
	cout << endl << endl;
	show_hash_table(&table, size);
	cout << endl << endl;
	cout << "Кол-во коллизий для " << size << " строк:" << collision_count;
	delete[] arr;
	return 0;
}