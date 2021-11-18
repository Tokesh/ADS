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
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        string a,b;
        cin >> a >> b;
        string q = b+'#'+a;
        vector<int>z = pref_f(q);
        vector<int> res;
        for(int e=0;e<q.size();e++){
            if(z[e] == b.size()){
                res.push_back(e-2*b.size()+1);
            }
        }
        if(res.size() != 0){
            cout << res.size() << endl;
            for(int e=0;e<res.size();e++){
                cout << res[e] << ' ';
            }
            cout << endl;
        }
        else{
            cout << "Not Found" << endl;
        }

    }
    return 0;

}