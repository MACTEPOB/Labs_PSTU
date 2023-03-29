#include <iostream>
using namespace std;

void countSort(int a[], int size)
{
    int* output = new int[size];
    int* count;
    int max = a[0];

    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    count = new int[max + 1];
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[a[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        a[i] = output[i];
    }
    delete[] count;
    delete[] output;
}

int main()
{
    srand(time(NULL));
    int size;
    cout << "Enter no of elements: ";
    cin >> size;
    int* a = new int[size];
    cout << "Incoming sequence: ";
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 101;
        cout << a[i] << " ";
    }
    cout << endl;

    countSort(a, size);
    cout << "Sorted sequence: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}