#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool good = true;
vector<int>g[5000];
vector<int>visited(5000);
vector<int>rr;


void dfs(int v){
    if(visited[v] == 2) return;
    visited[v] = 1;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(visited[to] == 0) dfs(to);
        else if(visited[to] == 1){
            good = false;
        }
    }
    visited[v] = 2;
    rr.push_back(v);
}


int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        dfs(i);
    }
    if(good == false){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    reverse(rr.begin(),rr.end());
    for(int i=0;i<rr.size();i++){
        cout << rr[i] + 1 << ' ' ;
    }
    return 0;
}