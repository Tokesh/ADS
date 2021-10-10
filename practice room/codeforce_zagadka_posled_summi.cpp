#include <iostream>
#include <vector>
using namespace std;

struct MinHeap{
    vector<int>a;
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i + 1;
    }
    int right(int i){
        return 2*i + 2;
    }
};


int main(){

    return 0;
}