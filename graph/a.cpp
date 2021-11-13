#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n][n];
    int edge=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j] == 1) edge += 1;
        }
    }
    cout << n << ' ' << edge << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1) cout<< i+1 << ' ' << j+1 << endl;
        }
    }
    return 0;
}