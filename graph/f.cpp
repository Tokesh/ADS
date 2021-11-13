#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int g[n][n];
    int prev = 0;
    bool ok = false;
    for(int i=0;i<n;i++){
        int cnt =0;
        for(int j=0;j<n;j++){
            cin >> g[i][j];
            if(g[i][j] == 1) cnt += 1;
        }
        if(i == 0) prev = cnt;
        else{
            if(prev != cnt){
                ok = true;
                break;
            }
        }
    }
    if(ok == true) cout << "NO";
    else cout << "YES";

    return 0;
}