#include <iostream>
using namespace std;
int n,m;
bool used[500][500];
char a[500][500];
int cnt =0;

void dfs(int i, int j){
    if( i < 0 || i >=n || j < 0 || j >= m) return;
    if(used[i][j]) return;
    if(a[i][j] == '#') return;
    used[i][j] = 1;
    a[i][j] = '0' + cnt;
    dfs(i+1, j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i, j-1);
}


int main(){
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(used[i][j]!=true && a[i][j]=='.'){
                cnt += 1;
                dfs(i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}