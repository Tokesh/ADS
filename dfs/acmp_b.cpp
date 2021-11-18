#include <iostream>
#include <vector>
using namespace std;
vector<int>g[100];
bool used[105];
int cnt;

void dfs(int v){
    if(used[v]) return;
    used[v] = true;
    cnt += 1;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        dfs(to);
    }
}

int main(){
    int n,s;
    cin >> n >> s;
    while(true){
        int a,b;
        cin >> a ;
        if(a != 0){
            cin >> b;
        }
        else break;
        a--;
        b--;
        g[a].push_back(b);
    }
    dfs(s-1);
    if(cnt == n) cout <<"Yes";
    else cout <<"No";
    return 0;
}