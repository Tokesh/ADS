#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[100000];
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i=0;i<k;i++){
        int cnt=0;
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int l=0,r=n-1, resu1;
        while(l<=r){
            int mid = (r+l) / 2;
            if(l1 <= arr[mid]){
                resu1 = mid;
                r = mid-1;
            }else{
                l=mid+1;
            }
        }
        l = 0, r=n-1;
        int resu2=0;
        while(l<=r){
            int mid = (r+l) / 2;
            if(r1 >= arr[mid]){
                resu2 = mid;
                l = mid+1;
            }else{
                r=mid-1;
            }
        }
        l1=l2;
        r1=r2;
        int sec_resu1=0, sec_resu2 = 0;
        l=0, r=n-1;
        while(l<=r){
            int mid = (r+l) / 2;
            if(l1 <= arr[mid]){
                sec_resu1 = mid;
                r = mid-1;
            }else{
                l=mid+1;
            }
        }
        l = 0, r=n-1;
        while(l<=r){
            int mid = (r+l) / 2;
            if(r1 >= arr[mid]){
                sec_resu2 = mid;
                l = mid+1;
            }else{
                r=mid-1;
            }
        }
        if(resu2 > sec_resu1) cnt = sec_resu2 - resu1 +1;
        else{
            if(resu2 -resu1 +1> 0) cnt += resu2-resu1 + 1;
            if(sec_resu2 -sec_resu1 +1> 0) cnt += sec_resu2-sec_resu1 + 1;
        }
        cout << cnt << endl;
    }
    return 0;
}