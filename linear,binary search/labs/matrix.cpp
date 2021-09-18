#include <iostream>
using namespace std;
int main(){
    int arr[750][750];
    int row[1000];
    int stolbec[1000];
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int mini=100000;
        for(int j =0;j<k;j++){
            cin >> arr[i][j];
            // find min of row
            if(arr[i][j] < mini){
                mini = arr[i][j];
            }
        }
        row[i]=mini;
    }
    for(int j=0;j<k;j++){
        int maxi = -1000000;
        for(int i=0;i<n;i++){
            // find max of column
            if(maxi < arr[i][j]){
                maxi = arr[i][j];
            }
        }
        stolbec[j]=maxi;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(arr[i][j]==row[i] && arr[i][j] == stolbec[j]){
                cnt++;
            }
        }
    }
    cout << cnt;

}