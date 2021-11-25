#include <iostream>
#include <vector>
using namespace std;

int n,x;
vector<int>g[105];
vector<bool>used(105,0);
int cnt = 0;

void dfs(int v){
    if(used[v] == true) return;
    used[v] = true;
    cnt++;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        dfs(to);
    }
}


int main(){
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int k;
            cin >> k;
            if(k == 1){
                g[i].push_back(j);
            }
        }
    }
    dfs(x);
    cout << cnt;
    return 0;
}