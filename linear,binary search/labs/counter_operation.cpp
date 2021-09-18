#include <iostream>
using namespace std;
int main(){
    int arr[100000], maxi = -1000000, mini = 1000000;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
        if(arr[i] < mini){
            mini = arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i] == maxi) arr[i]=mini;
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
}