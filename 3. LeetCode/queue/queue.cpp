#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int *arr;
    int capacity;

public:
    Queue(int cap) {
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0;
        arr = new int[capacity];
    }

    bool isFull() { return size == capacity; }
    bool isEmpty() { return size == 0; }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
        cout << data << " enqueued to queue\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        cout << item << " dequeued from queue\n";
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    int Size() { return size; }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.Front() << endl;
    cout << "Rear element: " << q.Rear() << endl;

    q.dequeue();
    cout << "After one dequeue, front: " << q.Front() << endl;

    return 0;
}
