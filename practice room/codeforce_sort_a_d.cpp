#include <iostream>
using namespace std;
int main(){
    int n;
    char x;
    cin >> n >> x;
    if(x == 'a'){
        for(int i=1;i<=n;i++){
            cout << i;
            if(i != n) cout << ' ';
        }
    }else{
        for(int i=n;i>=1;i--){
            cout << i;
            if(i != 1) cout << ' ';
        }
    }
    return 0;
}