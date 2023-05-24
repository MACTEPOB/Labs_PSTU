#include <iostream>
using namespace std;

class Node {
    friend class List;
    friend class Iterator;
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

class Iterator {
    friend class Node;
    friend class List;
private:
    Node* current;
public:
    Iterator(Node* node) : current(node) {}
    bool operator!=(const Iterator& other) const;
    Iterator& operator++();
    int operator*() const;
};

class List {
    friend class Node;
    friend class Iterator;
private:

    Node* head;
    int size;

public:
    List() : head(nullptr), size(0) {}
    List(const List& other) : head(nullptr), size(0) {
        Node* curr = other.head;
        while (curr) {
            push_back(curr->key);
            curr = curr->next;
        }
    }
    ~List() {clear();}
    List& operator=(const List& other);
    void push_back(int key);
    void clear();
    int operator[](int index) const;
    int operator()() const;
    List& operator*(int factor);
    Iterator begin() const;
    Iterator end() const;
    void show(List list);
};


