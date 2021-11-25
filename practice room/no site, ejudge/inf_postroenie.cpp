#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    bool ok = true;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(a < b){
            ok = false;
        }
    }
    if(ok == false) cout <<"No";
    else cout <<"Yes";
    return 0;
}