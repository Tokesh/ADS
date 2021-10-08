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
            cout <<h[i];
            if(i != h.size()) cout << ' ';
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
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        if(l<HeapSize && r<HeapSize){
            if(h[l]>h[r])
                return l;
            else if (h[l] == h[r])
                return l;
            else
                return r;
        }
        else if(l<HeapSize){
            return l;
        }
        else {
            return -1;
        }
    }
    void add(int x){
        h.push_back(x);
        HeapSize++;
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
    void makeHeap(){
      for (int i = h.size()/2; i >= 0; i--){
        Shift_down(i,0);
      }
    }
    int extract_max(){
        int pos = 0;
        swap(h[0], h[h.size()-1]);
        HeapSize--;
        h.pop_back();
        if (h.size() > 1){
            if(max_child(pos) == (-1)){
                return 1;
            }else{
                while(max_child(pos) != (-1)){
                    int mx = max_child(pos);
                    if(h[pos]<h[mx]){
                        swap(h[pos],h[mx]);
                        pos=mx;
                    }
                    else break;
                }
            }
        }
        return pos+1;
    }

    int getMax(){
        return h[0];
    }
};

int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int n;
    Heap h;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        h.add(x);
    }
    h.makeHeap();
    int temp = h.HeapSize;
    vector<int>zxc;
    for(int i=0;i<temp;i++){
        h.print();
        if(i != temp) cout << endl;
        zxc.push_back(h.getMax());
        h.extract_max();
    }
    for(int i=zxc.size()-1;i>=0;i--){
        cout << zxc[i] << ' ';
    }
    return 0;
}