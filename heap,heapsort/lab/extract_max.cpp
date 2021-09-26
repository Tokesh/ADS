#include <iostream>
#include <vector>
using namespace std;

struct heapi{
    vector<int>a;
    int sz;
    heapi(){
        sz=0;
    }

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }

    void insert(int k){
        a.push_back(k);
        sz++;
        int i = a.size()-1;
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    bool heapify(int i){
        if(left(i) > sz-1) return false;
        int temp = i;
        int j = left(i);
        if(right(i) < sz && a[right(i)] > a[j]) j = right(i);
        if(a[i] < a[j]){
            temp = j;
            swap(a[i], a[j]);
            heapify(j);
        }
        cout << temp+1;
        return true;
    }
    bool extract_max(){
        swap(a[0], a[a.size()-1]);
        sz--;
        a.pop_back();
        if (a.size() > 0)
            if(heapify(0) == true){
                return true;
            }
        cout << 1;
        return false;
    }
    int get_max(){
        return a[0];
    }

    void DecrKey(int i, int num){
        a[i] = a[i] - num;
        heapify(i);
    }
    void extract_max_full(){
        int temp1 = a.size();
        for(int i=0;i<temp1-1;i++){
            int temp = get_max();
            extract_max();
            cout << ' ' << temp;
            if(i != temp1-2) cout << endl;
        }
        
    }
    void print_m(){
        for(int i=0;i<sz;i++){
            cout << a[i] << ' ';
        }
    }

};

int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    heapi qq;
    int n,k;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k;
        qq.insert(k);
    }
    qq.extract_max_full();
    return 0;
}