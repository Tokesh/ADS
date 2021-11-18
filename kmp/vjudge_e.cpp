#include <iostream>
#include <vector>
using namespace std;

vector<int> pref_f(string s){
    int n = s.size();
    vector<int>res(n);
    res[0]=0;
    for(int i=1;i<n;i++){
        int j = res[i-1];
        while(j > 0 && s[i] != s[j]){
            j = res[j-1];
        }
        if(s[i]==s[j]) j = j + 1;
        res[i]=j;
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    while(true){
        if(s == ".") break;
        vector<int> z = pref_f(s);
        int k = s.size()-z[s.size()-1];
        if(s.size() % k == 0) cout << s.size() / k << endl;
        else cout << 1 << endl;
        cin >> s;
    }
    return 0;

}