#include <iostream>
#include <vector>
using namespace std;

string s;
vector<int> pref_f(string s){
    int n = s.size();
    vector<int>res(n);
    res[0] = 0;
    for(int i=1;i<n;i++){
        int j = res[i-1];
        while(j > 0 && s[j] != s[i]){
            j = res[j-1];
        }
        if(s[j]==s[i]) j = j + 1;
        res[i] = j;
    }
    return res;
}


int main(){
    cin >> s;
    vector<int> z = pref_f(s);
    int k = s.size() - z[s.size()-1];
    if(s.size() % k == 0) cout << s.size()/k;
    else cout << 1;
    return 0;
}