#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    set<string>z1;
    set<string>z2;
    set<string>together;
    map<string,int>zxc;
    int n,m;
    string x;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x;
        z1.insert(x);
    }
    for(int i=0;i<m;i++){
        cin >> x;
        z2.insert(x);
    }
    if(n > m) cout <<"YES";
    else if(n < m) cout <<"NO";
    else{
        set_intersection(z1.begin(), z1.end(), z2.begin(), z2.end(), inserter(together, together.begin()));
        if(together.size() % 2 != 0) m--;
        if(n > m){
            cout <<"YES";
        }else{
            cout <<"NO";
        }
        return 0;
    }
}