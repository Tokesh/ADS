#include <iostream>
#include <vector>

using namespace std;

struct Heap{
    vector<int> h; 
    int HeapSize;
    Heap(){
        HeapSize = 0;
    }
    void print(){
        for(int i = 0; i < h.size(); i++){
            cout <<h[i] << " ";
        }
    }
    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return (i * 2) + 1;
    }
    int right(int i){
        return (i * 2) + 2;
    }
    int max_child(int i){
        int l = left(i);
        int r = right(i);
        if(l < HeapSize && r < HeapSize){
            if(h[l]>h[r])
                return l;
            else
                return r;
        }
        else if(l < HeapSize) return l;
        else return -1;
    }
    void add(int x){
        h.push_back(x);
        HeapSize++;
        int i = HeapSize - 1;
        while(i > 0 && h[parent(i)] < h[i]){
            swap(h[parent(i)], h[i]);
            i = parent(i);
        }
    }
    int Shift_up(int pos, int x){
        h[pos] += x;
        while(pos > 0 && h[parent(pos)] < h[pos]){
            swap(h[parent(pos)], h[pos]);
            pos = parent(pos);
        }
        return pos+1;
    }

    int Shift_down(int pos, int x){
        h[pos] -= x;
        while(max_child(pos) != (-1)){
            int mx=max_child(pos);
            if(h[pos]<h[mx]){
                swap(h[pos],h[mx]);
                pos=mx;
            }
            else break;
        }
        return pos+1;
    }
};

int main(){
    int n;
    Heap h;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        h.add(x);
    }
    int q;
    cin >> q;
    while(q--){
        int pos, x;
        cin >> pos >> x;
        cout<< h.Shift_down(pos-1,x) << endl;
    }
    h.print();
    return 0;
}