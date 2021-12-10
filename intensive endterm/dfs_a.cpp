#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int>g[105];
vector<int>used(105);
int d[105];
int f[105];
int cnt = 1;

void dfs(int v){
    if(used[v]) return;
    d[v] = cnt++;
    used[v] = true;
    int x = cnt + 1;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(!used[to]) dfs(to);
    }
    f[v] = cnt++;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        for(int j=0;j<b;j++){
            int x;
            cin >> x;
            g[a].push_back(x);
        }
        sort(g[a].begin(),g[a].end());
    }
    dfs(1);
    for(int i=1;i <=n;i++){
        cout << i << ' ' << d[i] << ' ' << f[i] << endl;
    }

}