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
            if(i!= h.size()-1) cout << ' ';
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
            if(h[l]>=h[r])
                return l;
            else
                return r;
        }
        else if(l < HeapSize) return l;
        else return -1;
    }
    int add(int x){
        h.push_back(x);
        HeapSize++;
        int i = HeapSize - 1;
        while(i > 0 && h[parent(i)] < h[i]){
            swap(h[parent(i)], h[i]);
            i = parent(i);
        }
        return i+1;
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
    int n,m;
    Heap h;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin>>x;
        if(x==1){
            if(h.HeapSize == 0) cout << -1 << endl;
            else if(h.HeapSize == 1){
                int max_elem = h.getMax();
                cout << 0 << ' ' << max_elem << endl;
                h.extract_max();
            }
            else if(h.HeapSize > 1){
                int max_elem = h.getMax();
                cout << h.extract_max() << ' ' << max_elem << endl;
            }

        }

        if(x == 2){
            int zxc;
            cin >> zxc;
            if(h.HeapSize == n){
                cout << -1 << endl;
            }else{
                cout << h.add(zxc) << endl;
            }
        }
    }
    h.print();
    return 0;
}