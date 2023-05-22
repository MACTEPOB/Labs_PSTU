#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteNode(Node** head, int pos) {
    if (*head == nullptr)
        return;
    Node* temp = *head;
    if (pos == 0) {
        *head = temp->next;
        delete temp;
        return;
    }
    for (int i = 0; temp != nullptr && i < pos - 1; i++)
        temp = temp->next;
    if (temp == nullptr || temp->next == nullptr)
        return;
    Node* nextNode = temp->next->next;
    delete temp->next;
    temp->next = nextNode;
}

void insertNode(Node** head, int data, int pos) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (pos == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp != nullptr && i < pos - 1; i++)
        temp = temp->next;
    if (temp == nullptr)
        return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
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
        insertNode(&head, value, i);
    }
    cout << "Исходный список: ";
    printList(head);
    int deletePos;
    cout << "Введите номер элемента для удаления: ";
    cin >> deletePos;
    deleteNode(&head, deletePos);
    cout << "Список после удаления элемента с номером " << deletePos << ": ";
    printList(head);
    int insertPos, insertVal;
    cout << "Введите номер позиции для добавления элемента: ";
    cin >> insertPos;
    cout << "Введите значение элемента для добавления: ";
    cin >> insertVal;
    insertNode(&head, insertVal, insertPos);
    cout << "Список после добавления элемента " << insertVal << " с номером " << insertPos << ": ";
    printList(head);
    return 0;
}