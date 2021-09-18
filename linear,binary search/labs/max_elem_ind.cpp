#include <iostream>
using namespace std;
int main(){
    int arr[100000], maxi = -1000000, maxi_ind=1;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i] > maxi){
            maxi = arr[i];
            maxi_ind = i+1;
        }
    }
    cout << maxi_ind;
}