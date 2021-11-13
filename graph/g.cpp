#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int g[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }

    bool ok = false;
    for(int i=0;i<n;i++){
        if(g[i][i] == 1){
            cout << "NO";
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j] == 1 && g[j][i] != 1){
                ok = true;
                break;
            }
        }
    }
    if(ok == false){
        cout <<"NO";
    }else{
        cout <<"YES";
    }
    return 0;
}