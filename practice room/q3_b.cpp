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
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        string z="";
        for(int j=a;j<=b;j++){
            z += s[j];
        }
        z += "#" + s;
        vector<int>amr = pref_f(z);
        int cnt =0;
        for(int j=0;j<z.size();j++){
            if(amr[j] == b-a + 1) cnt += 1;
        }
        cout << cnt << endl;
    }
    return 0;
}