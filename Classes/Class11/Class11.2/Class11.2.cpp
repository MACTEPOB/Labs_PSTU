#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

class Pair {
public:
    int first;
    double second;

    Pair(int f, double s) : first(f), second(s) {}
    friend ostream& operator<<(ostream& os, const Pair& pair) {
        os << pair.first << ":" << fixed << setprecision(1) << pair.second << " ";
        return os;
    }
};

vector<Pair> createContainer(int size) {
    vector<Pair> container;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 10.0);
    for (int i = 0; i < size; ++i) {
        int first = rand() % 10;
        double second = dis(gen);
        container.push_back(Pair(first, second));
    }
    return container;
}

void addMin(vector<Pair>& container, int position) {
    auto minElement = min_element(container.begin(), container.end(),
        [](const Pair& p1, const Pair& p2) { return p1.first < p2.first; });
    container.insert(container.begin() + position, *minElement);
}

double Average(const vector<Pair>& container) {
    double sum = 0.0;
    for (const Pair& pair : container) {
        sum += pair.first;
    }
    return sum / container.size();
}

void removeLess(vector<Pair>& container) {
    double average = Average(container);
    container.erase(remove_if(container.begin(), container.end(),
        [average](const Pair& pair) { return pair.first < average; }), container.end());
}

void divideByMax(vector<Pair>& container) {
    auto maxElement = max_element(container.begin(), container.end(),
        [](const Pair& p1, const Pair& p2) { return p1.first < p2.first; });
    if (maxElement->first != 0) {
        for (Pair& pair : container) {
            pair.first /= maxElement->first;
        }
    }
}

void print(const vector<Pair>& container) {
    for (const Pair& pair : container) {
        cout << pair;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    int size;
    cout << "Введите размер контейнера: ";
    cin >> size;
    vector<Pair> container = createContainer(size);
    cout << "Исходный контейнер: ";
    print(container);
    int position;
    cout << "Введите позицию для добавления минимального элемента: ";
    cin >> position;
    addMin(container, position);
    cout << "Контейнер после добавления минимального элемента на позицию " << position << ": ";
    print(container);
    removeLess(container);
    cout << "Контейнер после удаления значений меньше среднего арифметического: ";
    print(container);
    divideByMax(container);
    cout << "Контейнер после деления каждого элемента на максимальный элемент: ";
    print(container);
    return 0;
}