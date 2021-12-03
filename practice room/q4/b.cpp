#include <iostream>
#include <vector>
using namespace std;

int arr[1000][1000];

int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            /* int x;
            cin >> x;
            arr[i].push_back(x); */
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        bool ok = true;
        if(a > n || b > n || c > n || a < 0 || b < 0 || c < 0) ok = false;
        if(ok == true && arr[a][b] == 1 && arr[a][c] == 1 && arr[b][a] == 1 && arr[b][c] == 1 && arr[c][a] == 1 && arr[c][b] == 1){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}