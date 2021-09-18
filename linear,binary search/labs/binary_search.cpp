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
        bool ok = false;
        int l=0,r=n-1;
        while(l <= r && ok == false){
            int mid = (l+r)/2;
            if(arr[mid] >x){
                r=mid-1;
            }else if(arr[mid] < x){
                l=mid+1;
            }else{
                ok = true;
            }
        }
        if(ok == false) cout << "NO" << endl;
        else cout << "YES" << endl;

    }
}