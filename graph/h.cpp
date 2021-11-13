#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int g[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        int x,k;
        cin >> x >> k;
        x--;
        k--;
        g[x][k] = 1;
        g[k][x] = 1;
    }
    bool ok = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i != j && g[i][j] == 0){
                ok = false;
            }
        }
    }
    if(ok == true) cout <<"YES";
    else cout <<"NO";
    return 0;
}