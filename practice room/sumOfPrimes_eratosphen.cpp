#include <iostream>
using namespace std;

int p[100000];

void mark_prime(int n){
    for(int i=2;i*i <= n;i++){
        if(p[i] == 0){
            int k = i;
            while(k + i <= n){
                k += i;
                p[k] = 1;
            }
        }
    }
}


int main(){
    int n;
    cin >> n;
    mark_prime(n);
    for(int i=4;i<n;i++){
        if(p[i] == 0 && p[n-i]== 0 && n-i != 1 && n-i != 0){
            cout << i << ' ' << n-i << endl;
        }
    }
    return 0;
}