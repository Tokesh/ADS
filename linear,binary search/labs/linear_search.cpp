#include <iostream>
using namespace std;
int main(){
    int n;
    int arr[100000];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    for(int i=0;i<n;i++){
        if(arr[i] == k) cout << i+1 << ' ';
    }
    return 0;
}