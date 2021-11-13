#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n][n];
    map<int,int>istoki;
    map<int,int>stoki;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                istoki[j] += 1;
                stoki[i] = 1;
            }
        }
    }  
    vector<int>res;
    for(int i=0;i<n;i++){
        if(istoki[i] == 0) res.push_back(i);
    }
    cout << res.size() << ' ';
    for(int i=0;i<res.size();i++){
        cout << res[i] + 1 << ' ';
    }
    res.clear();
    for(int i=0;i<n;i++){
        if(stoki[i]==0) res.push_back(i);
    }
    cout << endl;
    cout << res.size() << ' ';
    for(int i=0;i<res.size();i++){
        cout << res[i] + 1 << ' ';
    }
    return 0;
}