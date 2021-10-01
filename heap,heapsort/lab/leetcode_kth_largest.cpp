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
        cout << endl;
    }

};

class KthLargest {
public:
    int j;
    MinHeap qq;
    KthLargest(int k, vector<int>& nums) {
        j = k;
        for(int i=0;i<nums.size();i++){
            qq.insert(nums[i]);
            if(qq.a.size()>j) qq.extractMin();
        }
    }
    int add(int val) {
        qq.insert(val);
        if(qq.a.size()>j) qq.extractMin();
        return qq.getMin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */