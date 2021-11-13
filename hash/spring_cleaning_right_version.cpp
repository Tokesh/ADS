#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result;
int p=31;
long long p_pow[100000];
vector<long long> h(300000);
string s;


void pow_func(){
    p_pow[0] = 1;
    for(int i=1;i<100000;i++){
        p_pow[i] = p_pow[i-1] * p;
    }
}
void hash_s(){
    for(int i=0;i<s.size();i++){
        h[i] = (s[i]-'a'+1)*p_pow[i];
        if(i != 0) h[i] += h[i-1];
    }
}
int diff_substr(int l){
    result = 0;
    vector<long long> hs(s.size()-l+1);
    for(int i=0;i<s.size()-l+1;i++){
        long long cur_h = h[i+l-1];
        if(i!=0) cur_h -= h[i-1];
        cur_h *= p_pow[s.size()-i-1];
        hs[i] = cur_h;
    }
    sort(hs.begin(),hs.end());
    hs.erase(unique(hs.begin(),hs.end()), hs.end());
    result += hs.size();
    return result;
}

int main(){
    int t;
    int N,K;
    cin >> t;
    pow_func();
    for(int i=0;i<t;i++){
        cin >> N >> K >> s;
        hash_s();
        cout << diff_substr(K) << endl;
    }
    return 0;
}