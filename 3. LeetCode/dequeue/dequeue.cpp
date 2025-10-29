#include <iostream>
using namespace std;

#define SIZE 10

class Deque {
private:
    int arr[SIZE];
    int front, rear, count;

public:
    Deque() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Check if deque is full
    bool isFull() {
        return count == SIZE;
    }

    // Check if deque is empty
    bool isEmpty() {
        return count == 0;
    }

    // Insert element at front
    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        front = (front - 1 + SIZE) % SIZE;
        arr[front] = x;
        count++;
        cout << x << " inserted at front\n";
    }

    // Insert element at rear
    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
        cout << x << " inserted at rear\n";
    }

    // Delete element from front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        cout << arr[front] << " deleted from front\n";
        front = (front + 1) % SIZE;
        count--;
    }

    // Delete element from rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        cout << arr[rear] << " deleted from rear\n";
        rear = (rear - 1 + SIZE) % SIZE;
        count--;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        return arr[rear];
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);
    dq.display();

    dq.deleteRear();
    dq.deleteFront();
    dq.display();

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    return 0;
}
