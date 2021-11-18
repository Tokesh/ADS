#include <iostream>
#include <vector>
using namespace std;
vector<int>z[105];
vector<int>g[105];
bool used[105];
int cnt;
int zx = 0;
 
void dfs(int v){
    if(used[v]) return;
    used[v] = true;
    z[zx].push_back(v);
    cnt += 1;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        dfs(to);
    }
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
        g[b].push_back(a);
    }
    
    for(int i=0;i<n;i++){
        cnt = 0;
        if(used[i] != true){
            dfs(i);
            zx += 1; 
        }
    }
    if(n- zx < 0){
        cout <<"NO";
    }else{
        cout << "YES";
    }
    return 0;
}