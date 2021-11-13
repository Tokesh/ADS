#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>G[n];
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
    }
    cout << n << endl;
    for(int i=0;i<n;i++){
        cout << G[i].size() << ' ';
        sort(G[i].begin(), G[i].end());
        for(int j=0;j<G[i].size();j++){
            cout << G[i][j] + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}