#include <iostream>
using namespace std;

struct StackNode {
    int data;
    StackNode* next;
};

struct Stack {
    StackNode* top;
    Stack() {
        top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int value) {
        StackNode* newNode = new StackNode;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        StackNode* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }
    void show() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack: ";
        StackNode* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int a = -1;
    int value;
    cout << "Menu:\n" << "Add element(1)\n" << "Delete element(2)\n" << "Show stack(3)\n" << "Exit(0)\n";
    do {
        cin >> a;
        switch (a) {
        case 1:
            cout << "Print element to add: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            cout << "Element has been removed\n";
            break;
        case 3:
            stack.show();
            break;
        case 0:
            cout << "cya";
            break;
        default:
            cout << "You picked the wrong number\n";
            break;
        }
    } while (a != 0);
    return 0;
}