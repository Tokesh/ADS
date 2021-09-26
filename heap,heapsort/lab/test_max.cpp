#include <iostream>
#include <vector>
using namespace std;
class MaxHeap{
    private:
    int _size{};
    vector<int> vect={-1};
    int p(int i){ return i>>1;};
    int l(int i){ return i<<1;};
    int r(int i){ return (i<<1)+1;};
    public:
        bool isEmpty() const{return _size == 0;};
        int getMax() const{return vect[1];};
        void insertItem(int val){
            if(_size + 1 >= vect.size()){
                vect.push_back(0);
            }
            vect[++_size] = val;
            shiftUp(_size);
            return;
        }
        void shiftUp(int i){
            if(i > _size) return;
            if(i == 1) return;
            if(vect[i] > vect[p(i)]){
                swap(vect[p(i)], vect[i]);
            }
            shiftUp(p(i));
        }
        int extractMax(){
            int maxNum = vect[1];
            swap(vect[1], vect[_size--]);
            shiftDown(1);
            return maxNum;
        }
        void shiftDown(int i){
            if(i > _size) return;
            int swapId = i;
            if(l(i) <= _size && vect[i] < vect[l(i)]){
                swapId = l(i);
            }
            if(r(i) <= _size && vect[swapId] < vect[r(i)]){
                swapId = r(i);
            }
            if( swapId != i){
                swap(vect[i], vect[swapId]);
                shiftDown(swapId);
            }
            return;
        }
        void print_m(){
            for(int i=1;i<=_size;i++){
                cout << vect[i] << ' ';
            }
        }
};


int main(){
    MaxHeap qq;
    vector<int>zx;
    int n,k;
    cin >>n ;
    for(int i=0;i<n;i++){
        cin >> k;
        qq.insertItem(k);
    }
    for(int i=0;i<n;i++){
        qq.print_m();
        zx.push_back(qq.getMax());
        qq.extractMax();
        cout << endl;
    }
    cout << endl;
    for(int i=0;i<zx.size();i++){
        cout << zx[i] << ' ' ;
    }
    return 0;
}