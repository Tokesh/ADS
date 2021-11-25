#include <iostream>
using namespace std;
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int z1,z2;
    for(int i=0;i<s1.size();i++){
        if(s1[i] >= 'A' && s1[i] <='Z'){
            z1 = i;
            break;
        }
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i] >= 'A' && s2[i] <='Z'){
            z2 = i;
            break;
        }
    }
    if(s1[z1] == s2[z2] && s1.substr(z1,s1.size()-z1) == s2.substr(z2,s2.size()-z2)){
        cout <<"YES";
    }else{
        cout <<"NO";
    }
    return 0;
}