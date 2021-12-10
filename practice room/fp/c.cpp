#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,m;
int parent[100000];
vector<int>g[1000];

int find_set (int v) {
	if (v == parent[v])
		return v;
	return find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b)
		parent[b] = a;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <=n ; i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            union_sets(find_set(i), find_set(g[i][j]));
            // just for safety we can add this if statement
            /* if(find_set(i) != find_set(g[i][j])){
                
            } */
        }
    }
    map<int,int>zxc;
    for(int i=1;i<=n;i++){
        zxc[find_set(i)] += 1;
    }
    map<int,int>::iterator it;
    int clan = 0;
    int maxi = -10000000;
    for(it = zxc.begin();it!=zxc.end();it++){
        if(it->second > maxi){
            maxi = it->second;
            clan = it->first;
        }
    }
    if(maxi == -10000000){
        cout << n;
        return 0;
    }
    int cnt =0;
    for(it = zxc.begin();it!=zxc.end();it++){
        if(it->first != clan) cnt++;
    }
    cout << cnt;
    return 0;
}