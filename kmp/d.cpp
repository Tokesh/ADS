#include <iostream>
#include <vector>
using namespace std;

vector<int> pref_f(string s){
    int n=s.size();
    vector<int>res(n);
    res[0] = 0;
    for(int i=1;i<n;i++){
        int j = res[i-1];
        while(j  > 0 && s[i] != s[j]){
            j = res[j-1];
        }
        if(s[i] == s[j]) j += 1;
        res[i] = j;
    }
    return res;
}


int main(){
    string s;
    cin >> s;
    vector<int> z = pref_f(s);
    for(int i=0;i<s.size();i++){
        cout << z[i] << ' ' ;
    }
    return 0;
}