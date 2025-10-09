#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        while (index < n) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < n && heap[left] < heap[smallest]) smallest = left;
            if (right < n && heap[right] < heap[smallest]) smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else break;
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (!heap.empty()) return heap[0];
        return -1; // or throw exception
    }

    void removeMin() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};
