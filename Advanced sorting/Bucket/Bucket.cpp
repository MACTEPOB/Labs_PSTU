#include <iostream>
using namespace std;

int findMax(int a[], int n)
{
    int i, max = a[0], cnt = 0;
    for (i = 1;i < n;i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    while (max > 0)
    {
        cnt++;
        max = max / 10;
    }

    return cnt;
}

void bucketSort(int a[], int* bucket[], int n)
{
    static int i, j[10], k, l, d = 1;
    int c;
    c = findMax(a, n);

    for (int m = 0;m < c;m++)
    {
        for (i = 0;i < 10;i++)
            j[i] = 0;
        for (i = 0;i < n;i++)
        {
            k = (a[i] / d) % 10;
            bucket[k][j[k]] = a[i];
            j[k]++;
        }

        l = 0;
        for (i = 0;i < 10;i++)
        {
            for (k = 0;k < j[i];k++)
            {
                a[l] = bucket[i][k];
                l++;
            }
        }
        d *= 10;
    }
}
int main()
{
    int n, * a, i;
    int* bucket[10];
    cout << "Enter no of element: ";
    cin >> n;
    a = new int[n + 1];
    for (i = 0;i < 10;i++)
        bucket[i] = new int[n];
    srand(time(NULL));
    cout << "Incoming sequence: ";
    for (i = 0;i < n;i++)
    {
        a[i] = rand() % 100;
        cout << " " << a[i];
    }
    cout << endl;
    bucketSort(a, bucket, n);

    cout << "Sorted sequence: ";
    for (i = 0;i < n;i++)
        cout << a[i] << " ";
    return 0;
}