#include <iostream>
#include <vector>
using namespace std;





int main(){
    int g[105][105];
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }
    vector<int>colors(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        colors[i] = x;
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j] == 1 && colors[i] != colors[j]) cnt++;
        }
    }
    cout << cnt / 2;

    return 0;
}