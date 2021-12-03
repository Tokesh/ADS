#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int INF = 1000000000;
int main(){
    int n,s,m;
    cin >> n >> m >> s;
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
    vector<int> d(n, INF);
    vector<int> p(n);
    d[s] = 0;
    set< pair<int,int> > q;
    q.insert(make_pair(d[s],s));
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int j = 0;j<g[v].size();j++){
            int to = g[v][j].first;
            int len = g[v][j].second;
            if(d[v] + len < d[to]){
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert(make_pair(d[to], to));
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << d[i] << ' ' ;
    }



    return 0;
}