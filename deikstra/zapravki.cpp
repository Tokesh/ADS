#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e6;

int main() {
    int n, start = 0;
    cin >> n;
    int end = n-1;
    int oil[n];
    for(int i=0;i<n;i++){
        cin >> oil[i];
    }
    int m;
    cin >> m;
    vector<pair<int,int>> g[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back({v,oil[u]});
        g[v].push_back({u,oil[v]});
    }
    vector<int> d(n, INF);
    vector<int> p(n);
    vector<bool> used(n);
    d[0]=0;
    for (int i = 1; i <= n; i++){
        int v = -1;
        for (int j = 0; j < n; j++){
        if (!used[j] && (v == -1 || d[j] < d[v])){
            v = j;
        }
        }
        if (d[v] == INF) break;
        used[v] = true;
        for (int j = 0; j < g[v].size(); j++){
        int to =  g[v][j].first;
        int distance = g[v][j].second;
        if (d[v] + distance < d[to]){
            d[to] = d[v] + distance;
            p[to] = v;
        }
        }
    }
    if (d[end] != INF){
        cout << d[end] << endl;
    }
    else{
        cout << -1 << endl;
    }
}