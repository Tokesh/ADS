#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int g[n][n];
    int a[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int cnt =0;
        for(int j=0;j<n;j++){
            if(g[i][j] == 1) cnt += 1;
        }
        cout << cnt << ' ' ;
    }
    
    return 0;
}