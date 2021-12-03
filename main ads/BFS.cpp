#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int main(){
    int n;
    cin >> n;
    vector<int>g[n+2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin >> x;
            if(x==1) g[i].push_back(j);
        }
    }   
    int s,end;
    cin >> s >> end;
    queue<int>q;
    vector<int>d(n+1), p(n+1);
    vector<bool>used(n+1);
    q.push(s);
    p[s] = -1;
    used[s] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0;i<g[v].size();i++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                d[to] = d[v]+1;
                p[to] = v;
            }
        }
    }
    if(used[end] ==false){
        cout << -1;
    }else{
        cout << d[end];
    }
    return 0;
}