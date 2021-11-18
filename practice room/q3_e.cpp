#include <iostream>
#include <vector>
using namespace std;

vector<int> pref_f(string s){
    int n=s.size();
    vector<int>res(n);
    res[0] = 0;
    for(int i=1;i<n;i++){
        int j = res[i-1];
        while(j > 0 && s[i] != s[j]) j = res[j-1];
        if(s[i] == s[j]) j = j + 1;
        res[i] = j;
    }
    return res;
}


int main(){
    string k;
    cin >> k;
    int res=0;
    string zxc = "";
    for(int i=1;i<=k.size();i++){
        string q = k.substr(0,i);
        vector<int> z = pref_f(q + "#" + k);
        int cnt = 0;
        for(int j=0;j<z.size();j++){
            if(z[j] == i) cnt += 1;
        }
        if(cnt >= 3){
            zxc = q;
        }else{
            break;
        }
        cout << cnt << endl;
    }
    if(zxc=="") cout <<"Just a legend";
    else cout << zxc;
    return 0;
}