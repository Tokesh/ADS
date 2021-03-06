#include <iostream>
#include <vector>

using namespace std;

struct MinHeap {
    vector<int> a;

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
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);

        
        if (right(i) < a.size() && a[left(i)] > a[right(i)])
            j = right(i);
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMin() {
        int root_value = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
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
    void print_m(){
        for(int i=0;i<a.size();i++){
            cout << a[i];
            if(i != a.size()-1) cout << ' ';
        }
    }

};

int main() {
    
    int n, x;
    cin >> n;
    MinHeap heap;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if(heap.a.size() < 2){
            heap.insert(x);
            cout << -1 << endl;
        }
        else if(heap.a.size()==2){
            heap.insert(x);
            cout << heap.a[0] * heap.a[1] * heap.a[2] << endl;
        }
        else{
            heap.insert(x);
            heap.extractMin();
            cout << heap.a[0] * heap.a[1] * heap.a[2] << endl;
        }
    }

    /* for (int i = 0; i < n; i++) { // O(n * logn)
        heap->extractMin();
    } */
    return 0;
}