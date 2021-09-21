#include <iostream>
using namespace std;
int main(){
    int arr[100000];
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        int l=0,r=n-1,res1=0;
        while(l<=r){
            int mid = (r+l) / 2;
            if(x <= arr[mid]){
                res1 = mid;
                r = mid-1;
            }else{
                l=mid+1;
            }
        }
        l = 0, r=n-1;
        int res2=0;
        while(l<=r){
            int mid = (r+l) / 2;
            if(x >= arr[mid]){
                res2 = mid;
                l = mid+1;
            }else{
                r=mid-1;
            }
        }
        if(arr[res2] != x && arr[res1] != x) cout << 0 << endl;
        else cout << res1+1 << ' ' << res2+1 << endl;
    }
}