#include <iostream>
using namespace std;


long long int p_pow[100000];


long long int hashes(string s){
    long long int h=0;
    for(int i=0;i<s.size();i++){
        h += (s[i]-'a'+1)*p_pow[i];
    }
    return h;
}


int main(){
    
    string s,t;
    cin >> s >> t;
    long long int p = 31;
    p_pow[0] = 1;
    for(int i=1;i<=s.size();i++){
        p_pow[i] = p_pow[i-1] * p;
    }
    long long int res = hashes(t);
    for(int i=0;i<s.size()-t.size()+1;i++){
        string temp = "";
        int cnt = 0;
        for(int j=i;j <s.size() && cnt < t.size() ;j++){
            temp += s[j];
            cnt++;
        }
        if(temp.size() != t.size()) continue;
        if(res == hashes(temp)) cout << i << ' ';
    }
    return 0;
}