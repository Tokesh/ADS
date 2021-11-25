#include <iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n;
    if(s.size() % 2 == 0) n = (s.size()/2) ;
    else n = s.size()/2;
    string k ="";
    for(int i=0;i<n;i++){
        if(s[i] != 'A' && s[i] != 'a' && s[i] != 'E' && s[i] != 'e' && s[i] != 'I' && s[i] != 'i' && s[i] != 'O' && s[i] != 'o' && s[i] != 'U' && s[i] != 'u' && s[i] != 'Y' && s[i]!='y'){
            k += s[i];
        }
    }
    for(int i=s.size()-1;i>=n;i--){
        k += s[i];
    }
    if(k[0] >= 'a' && k[0] <='z') k[0] -= 32;
    cout << k;
    return 0;
}