#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n,m;
int z = -1;
int mush = 0;
int cnt = 0;
vector<int>arr[1050];
map<pair<int,int>, int> used;
// 0 not used, 1 waiting , 2 used

void dfs(int i, int j){
    used[make_pair(i,j)]= true;
    //left
    if(j-1 >= 0){
        if(arr[i][j-1] == 1){
            arr[i][j-1] = 2;
            used[make_pair(i,j-1)] = 1;
            z++;
            mush--;
        }
    }
    //right
    if(j+1 < m){
        if(arr[i][j+1] == 1){
            arr[i][j+1] = 2;
            used[make_pair(i,j+1)] = 1;
            z++;
            mush--;
        }
    }
    //up
    if(i-1 >= 0){
        if(arr[i-1][j] == 1){
            arr[i-1][j] = 2;
            used[make_pair(i-1,j)] = 1;
            z++;
            mush--;
        }
    }
    //down
    if(i+1 >= 0){
        if(arr[i+1][j] == 1){
            arr[i+1][j] = 2;
            used[make_pair(i+1,j)] = 1;
            z++;
            mush--;
        }
    }
}


int main(){
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            used[make_pair(i,j)] = 0;
            if(x == 1) mush++;
            arr[i].push_back(x);
        }
    }
    while(mush != 0){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(used[make_pair(i,j)]==1){
                    cout << 1;
                    dfs(i,j); 
                }
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(used[make_pair(i,j)]==0 && arr[i][j] == 2){
                    cout << 2;
                    dfs(i,j);
                }
                
            }
        }
        
        cnt++;
    }
    cout <<"C"<< cnt;
    return 0;
}