#include <iostream>
#include <ctime>

using namespace std;

void merge(int a[], int l, int m, int r);

void mergeSort(int a[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    merge(a, start, mid, end);
}

void merge(int a[], int left, int mid, int right)
{
    int leftRange = mid - left + 1;
    int rightRange = right - mid;

    int* leftArr = new int[leftRange];
    int* rightArr = new int[rightRange];

    for (int i = 0; i < leftRange; i++)
    {
        leftArr[i] = a[left + i];
    }
    for (int i = 0; i < rightRange; i++)
    {
        rightArr[i] = a[mid + 1 + i];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = left;

    while (leftIndex < leftRange && rightIndex < rightRange)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex])
        {
            a[mergeIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            a[mergeIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    while (leftIndex < leftRange)
    {
        a[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    }
    while (rightIndex < rightRange)
    {
        a[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

int main()
{
    srand(time(0));
    int size;
    cout << "Enter no of elemets: ";
    cin >> size;
    int* a = new int[size];
    cout << "Incoming sequence: ";
    for (int i = 0; i < size; ++i)
    {
        a[i] = rand() % 101;
        cout << a[i] << " ";
    }
    cout << endl;
    mergeSort(a, 0, size - 1);
    cout << "Sorted sequence: ";
    for (int i = 0; i < size; ++i)
    {
        cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}