#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>g[120];
vector<int>visited(120);
bool used[105];
vector<int>rr;
const int NEW = 0;  
const int DURING = 1;
const int VISITED = 2;

void dfs(int v){
    visited[v] = DURING;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(visited[to] == NEW){
            dfs(to);
        }
        else if(visited[to] == DURING){
            cout << "Yes" << endl;
            exit(0);
        }
    }
    visited[v] = VISITED;
    rr.push_back(v);
}


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for(int j=0;j < n ;j++){
            int x;
            cin >> x;
            if(x == 1) g[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]) dfs(i);
    }
    cout << "No" << endl;
    /* reverse(rr.begin(),rr.end());
    for(int i=0;i<rr.size();i++){
        cout << rr[i] << " " ;
    } */
    return 0;
}