#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int G[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        
        for(int j=0;j<x;j++){
            int k;
            cin >> k;
            G[i][k-1] = 1;
        }
        
    }
    cout << n << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << G[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}