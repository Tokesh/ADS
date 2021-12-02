#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> p[25][25];
bool ok_c(int x, int y){
    return x > 0 && y > 0 && x <= 25 && y<=25;
}

int main(){
    
    const int INF = 10000000;
    int n;
    cin >> n;
    int x,y;
    cin >> x >> y;
    int X,Y;
    cin >> X >> Y;
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    queue<pair<int,int>> q;
    int d[25][25];
    pair<int,int> p[25][25];
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            d[i][j] = INF;
        }
    }
    d[x][y] =0;
    q.push(make_pair(x,y));
    p[x][y] = make_pair(-1, -1);
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0;k<8;k++){
            int toX = i + dx[k];
            int toY = j + dy[k];
            if(ok_c(toX, toY) && d[toX][toY] > d[i][j] + 1){
                d[toX][toY] = d[i][j] + 1;
                p[toX][toY] = make_pair(i,j);
                q.push(make_pair(toX, toY));
            }
        }
    }
    vector<pair<int,int>>res;
    for(pair<int,int> z= {X,Y}; z.first != -1; z = p[z.first][z.second]){
        res.push_back(z);
    }
    
    cout << d[X][Y] << endl;
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout << res[i].first << ' ' << res[i].second << endl;
    }
    return 0;
}