#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == nullptr) {
            front = rear = temp;
            cout << x << " enqueued to queue\n";
            return;
        }
        rear->next = temp;
        rear = temp;
        cout << x << " enqueued to queue\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << temp->data << " dequeued from queue\n";
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    int Front() {
        if (front == nullptr)
            return -1;
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.Front() << endl;
    q.dequeue();
    cout << "After dequeue, front: " << q.Front() << endl;

    return 0;
}
