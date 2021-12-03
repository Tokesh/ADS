#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>res;
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
    res.push_back(v);
}

int main(){
    int n,s;
    cin >> n >> s;
    int a[n][n];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }
    for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
	reverse (res.begin(), res.end());

    return 0;
}