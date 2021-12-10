#include <iostream>
#include <vector>
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
    for(int i=1;i<=n;i++){
        cout << i << ' ' << find_set(i) << endl;
    }

    return 0;
}