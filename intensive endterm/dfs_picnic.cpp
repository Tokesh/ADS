#include <iostream>
#include <vector>
using namespace std;

vector<int>g[1005];
bool used[1005];
int cnt[1005];

void dfs(int v){
    used[v] = true;
    cnt[v]++;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(!used[to]) dfs(to);
    }
}


int main(){
    int t;
    cin >> t;
    for(int it = 0;it<t;it++){
        int res = 0;
        int k,n,m;
        cin >> k >> n >> m;
        for(int i=0;i<n;i++){
            used[i] = false;
            g[i].clear();
            cnt[i] = 0;
        }
        vector<int> people(k);
        for(int i=0;i<k;i++){
            cin >> people[i];
        }
        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        for(int i=0;i<k;i++){
            for(int j=1;j<=n;j++){
                used[j] = false;
            }
            dfs(people[i]);
        }
        for(int i=1;i<=n;i++){
            if(cnt[i] == k){
                res++;
            }
        }
        cout << "Case " << it << ": " <<res << endl;
    }
    return 0;
}