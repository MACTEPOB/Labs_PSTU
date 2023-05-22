#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void deleteElem(Node** head, int position, int K) {
    if (*head == nullptr)
        return;
    Node* temp = *head;
    for (int i = 0; temp != nullptr && i < position; i++)
        temp = temp->next;
    if (temp == nullptr)
        return;
    for (int i = 0; temp != nullptr && i < K; i++) {
        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;
        if (prevNode != nullptr)
            prevNode->next = nextNode;
        if (nextNode != nullptr)
            nextNode->prev = prevNode;
        delete temp;
        temp = prevNode;
    }
}

void insertElem(Node** head, int K) {
    if (*head == nullptr)
        return;
    Node* temp = *head;
    while (temp->next != nullptr)
        temp = temp->next;
    for (int i = 0; i < K; i++) {
        Node* newNode = new Node;
        cin >> newNode->data;
        newNode->prev = temp;
        newNode->next = nullptr;
        temp->next = newNode;
        temp = newNode;
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    Node* head = nullptr;
    int size;
    cout << "Введите размер списка: ";
    cin >> size;
    cout << "Введите элементы списка: ";
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    cout << "Исходный список: ";
    printList(head);
    int position, K;
    cout << "Введите номер элемента для удаления элементов перед ним: ";
    cin >> position;
    cout << "Введите количество элементов для удаления: ";
    cin >> K;
    deleteElem(&head, position-1, K);
    cout << "Список после удаления " << K << " элементов перед элементом с номером " << position << ": ";
    printList(head);
    cout << "Введите количество элементов для добавления в конец списка: ";
    cin >> K;
    cout << "Введите элементы для добавления: ";
    insertElem(&head, K);
    cout << "Список после добавления " << K << " элементов в конец: ";
    printList(head);
    return 0;
}