#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int INF = 2009000999;
int main(){
    int n,m,s;
    cin >> n >> m >> s;
    vector<pair<int,int>> g[n+2];
    for (int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    vector<int> d(n, INF);
    d[s] = 0;
    set< pair<int,int> > q;
    q.insert(make_pair(d[s],s));
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int j = 0;j<g[v].size();j++){
            int to = g[v][j].first;
            int distance = g[v][j].second;
            if(d[v] + distance < d[to]){
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + distance;
                q.insert(make_pair(d[to], to));
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << d[i] << ' ' ;
    }



    return 0;
}