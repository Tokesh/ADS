#include <iostream>
#include <vector>
using namespace std;

struct heap_m{
    int sz;
    vector<int>a;
    heap_m(){
        sz = 0;
    }

    int parent(int k){
        return (k-1)/2;
    }
    int left(int k){
        return (k*2 + 1);
    }
    int right(int k){
        return (k*2 + 2);
    }

    void insert(int n){
        sz++;
        a.push_back(n);
        int i = sz-1;
        while(i > 0 && a[i] > a[parent(i)]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    int get_min(){
        return a[0];
    }

    void heapify(int i){
        if(left(i) > sz-1) return;
        int j = left(i);
        if(right(i) <= sz-1 && a[right(i)] > a[j]){
            j = right(i);
        }
        if(a[i] < a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
        
    }

    void extract_min(){
        swap(a[0], a[sz-1]);
        sz--;
        heapify(0);
    }

    void decrKey(int i, int new_val){
        a[i] -= new_val;
        heapify(i);
    }

    void incrKey(int i, int new_val){
        a[i] += new_val;
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[i],a[parent(i)]);
            i = parent(i);
        }
        cout << i+1 << endl;

    }

    void print(){
        for(int i=0;i<sz;i++){
            cout << a[i];
            if(i != sz-1) cout << ' ';
        }
    }
    
};

int main(){
    /* freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout); */
    heap_m qq;
    int n,k;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> k;
        qq.insert(k);
    }
    int x;
    cin >> x;
    for(int i=0;i<x;i++){
        int a,b;
        cin >> a >> b;
        qq.incrKey(a-1, b);

    }
    qq.print();
    return 0;
}