#include <iostream>

using namespace std;

struct MinHeap {
    int a[100000];
    int size;
    MinHeap(){
        size = 0;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMin() {
        return a[0];
    }

    void siftUp(int i) {
        while (i > 0 && a[parent(i)] > a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void insert(int k) {
        a[size++] = k;
        int i = size - 1;
        siftUp(i);
    }

    void heapify(int i) {
        if (left(i) > size - 1)
            return;
        
        int j = left(i);
        if (right(i) < size && a[left(i)] > a[right(i)])
            j = right(i);
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMin() {
        int root_value = getMin();
        swap(a[0], a[size - 1]);
        size--;
        if (size > 0)
            heapify(0);
        return root_value;
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        siftUp(i);
    }

};

int main() {
    int n, x;
    cin >> n;
    MinHeap heap;
    for (int i = 0; i < n; i++) {
        cin >> x;
        heap.insert(x);
    }

    for (int i = 0; i < n; i++) {
        cout << heap.extractMin() << " ";        
    }
    return 0;
}