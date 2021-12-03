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
    if(n == 2){
        cout << 2;
        return 0;
    }
    mark_prime(100000);
    int arr[100000], z=0;
    for(int i=2;i<100000 && n != 0;i++){
        if(p[i] == 0){
            arr[z++] = i;
            n--;
        }
    }
    
    int cnt = 0;
    
    for(int i=0;i<z;i++){
        if(i == 0 || i == z-1) cnt++;
        else if(arr[i] - arr[i-1] != 2 && arr[i+1] - arr[i] != 2) cnt++;
    }
    cout << cnt;
    return 0;
}