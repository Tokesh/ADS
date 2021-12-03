#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n,m;
pair<int,int> p[100][100];
int arr[102][102];

int l_wall(int i,int j){
    while(arr[i][j] != 1 && j != -1){
        j--;
    }
    if(j == -1) return 0;
    return j - 1;
}
int r_wall(int i,int j){
    while(arr[i][j] != 1 && j != m-1){
        j++;
    }
    if(j == m-1) return m-2;
    return j;
}
int u_wall(int i,int j){
    while(arr[i][j] != 1 && i != -1){
        i--;
    }
    if(i == -1) return 0;
    return i - 1;
}
int d_wall(int i,int j){
    while(arr[i][j] != 1 && i != n-1){
        i++;
    }
    /* cout << i << ' ' << n-1 << ' ' << arr[i][j] << ' '  << j<< endl; */
    if(i == n-1) return n-2;
    return i - 1;
}

int main(){
    vector<int>res;
    int X,Y;
    map<pair<int,int>,int>dirki;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                X = i;
                Y = j;
                dirki[{X,Y}] = 1;
            }
        }
    }
    queue<pair<int,int>>q;
    map<pair<int,int>,int>d;
    
    for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j ++){
			d[make_pair(i,j)] = 10000;
		}
	}
    q.push({0,0});
    d[{0,0}] = 0;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        /* cout << i << ' ' << j << endl; */
        
        int l = l_wall(i,j);
        if(d[{i,l}] > d[{i,j}] + 1){
            d[{i,l}] = d[{i,j}] + 1;
            p[i][l] = make_pair(i,j);
            q.push({i,l});
        }
        int r = r_wall(i,j);
        if(d[{i,r}] > d[{i,j}] + 1){
            d[{i,r}] = d[{i,j}] + 1;
            p[i][r] = make_pair(i,j);
            q.push({i,r});
        }
        
        int u = u_wall(i,j);
        if(d[{u,j}] > d[{i,j}] + 1){
            d[{u,j}] = d[{i,j}] + 1;
            p[u][j] = make_pair(i,j);
            q.push({u,j});
        }

        int dz = d_wall(i,j);
        if(d[{dz,j}] > d[{i,j}] + 1){
            d[{dz,j}] = d[{i,j}] + 1;
            p[dz][j] = make_pair(i,j);
            q.push({dz,j});
        }
        /* cout << l << ' ' << r  << ' ' << u << ' ' << dz << endl; */
        if(dirki[{i,l}] == 1 || dirki[{i,r}] == 1 || dirki[{u,j}] == 1 || dirki[{dz,j}] == 1){
            int zx,zy;
            if(dirki[{i,l}] == 1){
                zx = i;
                zy = l;
            }
            if(dirki[{i,r}] == 1){
                zx = i;
                zy = r;
            }
            if(dirki[{u,j}] == 1){
                zx = u;
                zy = j;
            }
            if(dirki[{dz,j}] == 1){
                zx = dz;
                zy = j;
            }
            res.push_back(d[{zx,zy}]);
        }
        q.pop();
    }
    sort(res.begin(),res.end());
    cout << res[0];
    return 0;
}