#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int m, k, ai;
        cin >> m >> k;
        vector<int>zxc;
        for(int j=0;j<m;j++){
            cin >> ai;
            zxc.push_back(ai);
        }
        sort(zxc.begin(),zxc.end());
        int l=0, r=zxc.size()-1, res=0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(zxc[mid] >= k){
                res = zxc[mid];
                break;
            }else{
                l = mid+1;
            }
        }
        if(res == 0){
            int cnt=0;
            int temp1 = zxc[zxc.size()-1] + zxc[zxc.size()-2];
            if(temp1 * (k / temp1) >= k) cout << k/temp1 * 2 << endl;
            else if((temp1 * (k/temp1)) + zxc[zxc.size()-1] >= k) cout << (k/temp1) * 2 +1 << endl;
            else if((temp1 * (k/temp1)) + zxc[zxc.size()-1] + zxc[zxc.size()-2] >= k) cout << (k/temp1)*2 +2 << endl;
        }else{
            cout << 1 << endl;
        }
    }
    return 0;
}