class myQueue {
  private:
    int *arr;
    int front, rear;
    int capacity, size;

  public:
    myQueue(int n) {
        capacity = n;
        size = 0;
        arr = new int[n];
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int x) {
        if(isFull()){
            return;
        }
        rear++;
        arr[rear] = x;
        size++;
    }

    void dequeue() {
        if(isEmpty()){
            return;
        }
        front++;
        size--;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return arr[rear];
    }
};
