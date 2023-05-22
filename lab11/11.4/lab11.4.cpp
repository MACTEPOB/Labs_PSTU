#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
    int info;
    Node* next;
};

class Queue
{
    Node* head;

public:
    Queue();
    void push(int value);
    void pop();
    int peek() const;
    bool isEmpty() const;
    void print() const;
};

Queue::Queue()
    :head(nullptr)
{
}

void Queue::push(int value)
{
    Node* newNode = new Node;
    newNode->info = value;

    if (!head)
    {
        head = newNode;
        head->next = nullptr;
    }
    else
    {
        newNode->next = head->next;
        head->next = newNode;
    }
}

void Queue::pop()
{
    if (!head)
        return;

    Node* temp = head->next;
    delete head;
    head = temp;
}

int Queue::peek() const
{
    if (head)
        return head->info;
    else
        return 0;
}

bool Queue::isEmpty() const
{
    return !head;
}

void Queue::print() const
{
    cout << "QUEUE:" << endl;

    Node* temp = head;
    while (temp)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
}

void menu()
{
    cout << "MENU:" << endl;
    cout << "Push (1)" << endl;
    cout << "Pop (2)" << endl;
    cout << "Peek (3)" << endl;
    cout << "Print (4)" << endl;
    cout << "Exit (0)" << endl;
}

int main()
{
    Queue queue;
    menu();
    int selection;
    do
    {
        cin >> selection;
        switch (selection)
        {
        case 1:
            cout << "Enter value: ";
            int value;
            cin >> value;
            queue.push(value);
            break;
        case 2:
            queue.pop();
            break;
        case 3:
            cout << queue.peek() << endl;
            break;
        case 4:
            if (queue.isEmpty())
                cout << "Queue is empty" << endl;
            else
                queue.print();
            break;
        }
    } while (selection);

    return 0;
}
