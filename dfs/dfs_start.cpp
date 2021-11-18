#include <iostream>
#include <vector>
using namespace std;
vector<int>g[100];
bool used[105];

void dfs(int v){
    
    cout << v << endl;
    if(used[v]) return;
    used[v] = true;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        dfs(to);
    }
}

int main(){
    int n,m;
    cin >> n;
    int a[n][n];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }
    dfs(1);
    return 0;
}