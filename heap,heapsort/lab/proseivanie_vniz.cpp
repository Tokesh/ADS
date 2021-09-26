#include <iostream>
#include <vector>
using namespace std;

struct heapi{
    vector<int>a;
    heapi(){
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
        int i = a.size()-1;
        /* while(i > 0 && a[parent(i)] < a[i]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        } */
    }

    void heapify(int i){
        if(left(i) > a.size()-1) return;
        
        
        int temp = i;
        int j = left(i);

        if(right(i) < a.size() && a[right(i)] > a[j]) j = right(i);

        if(a[i] < a[j]){
            temp = j;
            swap(a[i], a[j]);
            heapify(j);
        }
        cout << temp+1 << endl;
    }
    void extract_max(){
        swap(a[0], a[a.size()-1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
    }
    int get_max(){
        return a[0];
    }

    void DecrKey(int i, int num){
        a[i] = a[i] - num;
        heapify(i);
    }
    void pros(){
        for(int i=0;i<a.size()-1;i++){
            heapify(a[i]);
        }
    }
    void print_m(){
        for(int i=0;i<a.size();i++){
            cout << a[i];
            if(i != a.size()-1) cout << ' ';
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
    qq.pros();
    /* int x;
    cin >> x;
    for(int i=0;i<x;i++){
        int a,b;
        cin >> a >> b;
        qq.DecrKey(a-1, b);
    } */
    qq.print_m();
    return 0;
}