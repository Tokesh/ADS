//10305 - Ordering Tasks
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<vector<int>>g(150);
bool used[150];
vector<int>res;

void dfs(int v){
    if(used[v] == true) return;
    used[v] = true;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(used[to] == false) dfs(to);
    }
    res.push_back(v);
}

int main(){
    while(cin >> n >> m && n!=0){
        res.clear();
        g.clear();
        for(int i=0;i<150;i++){
            used[i] = false;
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
        }
        for(int i=0;i<n;i++){
        if(used[i] != true) dfs(i);
        }
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            cout << res[i] + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}