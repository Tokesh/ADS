#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>G[n];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int cnt =0;
    for(int i=0;i<n;i++){
        if(G[i].size() > 1) cnt++;
    }
    cout << cnt;
    return 0;
}