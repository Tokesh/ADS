#include <iostream>
#include <vector>
using namespace std;

vector<int>g[1000];
vector<int>color(1000);

int rec(int c){
    if(c == 1) return 2;
    else return 1;
}


void dfs(int v,int c){
    color[v] = c;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(color[to] == c){
            cout << "NO";
            exit(0);
        }else if(color[to] == 0){
            dfs(to,rec(c));
        }
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
        if(color[i] == 0){
            dfs(i, 1);
        }
    }
    cout << "YES"<<endl;
    for(int i=0;i<n;i++){
        if(color[i] == 1){
            cout << i + 1 << ' ';
        }
    }




    return 0;
}