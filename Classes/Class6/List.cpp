#include <iostream>
#include "List.h"
using namespace std;

bool Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

Iterator& Iterator::operator++() {
    if (current) {
        current = current->next;
    }
    return *this;
}

int Iterator::operator*() const {
    if (current) {
        return current->key;
    }
    throw out_of_range("Iterator is not valid");
}

List& List::operator=(const List& other) {
    if (this == &other) {
        return *this;
    }

    clear();

    Node* curr = other.head;
    while (curr) {
        push_back(curr->key);
        curr = curr->next;
    }

    return *this;
}
void List::push_back(int key) {
    Node* newNode = new Node(key);
    if (!head) {
        head = newNode;
    }
    else {
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    size++;
}
void List::clear() {
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
    size = 0;
}
int List::operator[](int index) const {
    if (index < 0 || index > size) {
        return 0;
    }

    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->key;
}
int List::operator()() const {
    return size;
}
List& List::operator*(int factor) {
    Node* curr = head;
    while (curr) {
        curr->key *= factor;
        curr = curr->next;
    }
    return *this;
}

Iterator List::begin() const
{
    return Iterator(head);
}

Iterator List::end() const
{
    return Iterator(nullptr);
}

void List::show(List list)
{
    cout << "List elements: ";
    for (Iterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}