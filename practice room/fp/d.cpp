#include <iostream>
#include <vector>
using namespace std;


vector<int> pref_f(string s){
    int n = s.size();
    vector<int>res(s.size());
    res[0]=0;
    for(int i=1;i<n;i++){
        int j=res[i-1];
        while(j > 0 && s[i] != s[j]){
            j = res[j-1];
        }
        if(s[i] == s[j]) j = j+1;
        res[i]=j;
    }
    return res;
}



int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    string k = s + '#' + t + t;
    vector<int> z = pref_f(k);
    for(int i=0;i<k.size();i++){
        if(z[i] == t.size()){
            cout << i - 2*s.size();
            return 0;
        }
    }
    cout << -1;
    return 0;
}