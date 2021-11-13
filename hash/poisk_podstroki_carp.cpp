#include <iostream>
using namespace std;
int main(){
    string s, t;
    cin >> s >> t;
    long long int p = 31;
    long long int p_pow[s.size() + 2];
    p_pow[0] = 1;
    for(int i=1;i<=s.size();i++){
        p_pow[i] = p_pow[i-1] * p;
    }
    //ht
    long long int ht = 0;
    for(int i=0;i<t.size();i++){
        ht += (t[i]-'a'+1) * p_pow[i];
    }
    //h(s)
    long long int hs[s.size()+2];
    for(int i=0;i<s.size();i++){
        hs[i] = (s[i]-'a'+1) * p_pow[i];
        if(i != 0) hs[i] += hs[i-1];
    }
    for(int i=0;i<s.size();i++){
        long long temp = hs[i+t.size()-1];
        if(i != 0) temp -= hs[i-1];
        if(temp == ht * p_pow[i]) cout << i << ' ' ;
    }

    return 0;
}