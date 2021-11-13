#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<long long>p_pow(100000);
vector<long long>h(100000);
map<long long, string>zxc;
map<string, int>sprav;
int p = 31;
void pow_f(){
    p_pow[0] = 1;
    for(int i=1;i<100000;i++){
        p_pow[i] = p_pow[i-1]*p;
    }
}
void hash_m(string s){
    for(int i=0;i<s.size();i++){
        h[i] = (s[i]-'a'+1)*p_pow[i];
        if(i) h[i] += h[i-1];
    }
}

int main(){
    string s;
    cin >> s;
    pow_f();
    hash_m(s);
    int l = 10;
    vector<long long> hs(s.size()-l+1);
    for(int i=0;i<s.size()-l+1;i++){
        long long cur_h = h[i+l-1];
        if(i!=0) cur_h -= h[i-1];
        cur_h *= p_pow[s.size()-i-1];
        string k = s.substr(i,10);
        zxc[cur_h] = k;
        sprav[k] += 1;
        hs[i] = cur_h;
    }
    sort(hs.begin(),hs.end());
    hs.erase(unique(hs.begin(),hs.end()), hs.end());
    cout << "RES";
    for(auto it: hs){
        cout << zxc[it] << ' ' << it << endl;
    }
}