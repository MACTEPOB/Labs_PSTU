#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<float> createContainer()
{
    vector<float> container;
    int size;
    cout << "Введите размер контейнера: ";
    cin >> size;

    for (int i = 0; i < size; ++i)
    {
        float value;
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> value;
        container.push_back(value);
    }

    return container;
}

void findMinAndInsert(vector<float>& container)
{
    float minValue = *min_element(container.begin(), container.end());
    int position;
    cout << "Введите позицию для вставки минимального элемента: ";
    cin >> position;

    container.insert(container.begin() + position, minValue);
}

float Average(const vector<float>& container)
{
    float sum = 0.0f;
    for (float value : container)
    {
        sum += value;
    }

    return sum / container.size();
}

void removeValues(vector<float>& container)
{
    float average = Average(container);
    container.erase(remove_if(container.begin(), container.end(),
        [average](float value) { return value < average; }),
        container.end());
}

void divideByMax(vector<float>& container)
{
    float maxElement = *max_element(container.begin(), container.end());
    for (float& value : container)
    {
        value /= maxElement;
    }
}

void print(const vector<float>& container)
{
    cout << "Контейнер: ";
    for (float value : container)
    {
        cout << value << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    vector<float> container = createContainer();
    print(container);
    findMinAndInsert(container);
    print(container);
    removeValues(container);
    print(container);
    divideByMax(container);
    print(container);

    return 0;
}