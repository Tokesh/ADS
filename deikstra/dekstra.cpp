#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e6;

int main() {
    int n, s, end;
    cin >> n >> s >> end;
    s--;
    end--;
    vector<pair<int,int>> g[n];
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            int w;
            cin >> w;
            if (w != -1 && w != 0){
                g[i].push_back({j, w});
            }
        }
    }
    /* for (int i = 0; i < n; i ++){
        cout << i << "    ";
        for (int j = 0; j < g[i].size(); j ++){
        cout << "{" << g[i][j].first << "," << g[i][j].second << "} ";
        }
        cout << endl;
    } */
    /* cout << endl; */
    vector<int> d(n, INF);
    vector<int> p(n);
    vector<bool> used(n);
    d[s] = 0;
    for (int i = 1; i <= n; i++){
        int v = -1;
        /* cout << "Distances: " << endl;
        for (int i = 0; i < n; i ++){
        cout << d[i] << " ";
        } */
        /* cout << endl;
        cout << "Selected vertices: " << endl; */
        for (int j = 0; j < n; j++){
        if (!used[j] && (v == -1 || d[j] < d[v])){
            v = j;
            /* cout << v + 1 << " "; */
        }
        }
        /* cout << endl;
        cout << "Last Selected: " << endl;
        cout << v + 1 << endl << endl; */
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