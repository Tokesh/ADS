#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



int main(){
    
    vector<int>g[1000];
    int n;
    cin >> n;
    queue<int>q;
    vector<int>d(n+1, 0), p(n+1, 0);
    vector<bool>used(n+1, 0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }

    int a,b;
    cin >> a >> b;
    if(a == b){
        cout << 0;
        return 0;
    }
    if(b > n || a > n){
        cout << -1;
        return 0;
    }
    q.push(a);
    p[a] = -1;
    d[a] = 0;
    used[a] = true;
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0;i<g[v].size();i++){
            int to = g[v][i];
            if(used[to] != true){
                used[to]=true;
                q.push(to);
                d[to] = d[v]+1;
                p[to] = v;
            }
        }
    }
    if(used[b] == 0) cout << -1;
    else{
        cout << d[b] << endl;
        if(d[b] == 0){
            return 0;
        }
        vector<int>path;
        path.push_back(b);
        for(int i=p[b];i!=-1;i=p[i]){
            path.push_back(i);
        }
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++){
            cout << path[i] << ' ';
        }

    }
    return 0;
}