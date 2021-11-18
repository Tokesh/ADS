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
    int n;
    string s;
    cin >> s >> n;
    string k;
    cin >> k;
    string q = s + '#' + k;
    vector<int>z = pref_f(q);
    int cnt = 0;
    for(int i=0;i<z.size();i++){
        if(z[i] == s.size()) cnt++;
    }
    if(cnt >= n) cout <<"YES";
    else cout <<"NO";
    return 0;
}