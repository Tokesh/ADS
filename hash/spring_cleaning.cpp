#include <iostream>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int z=0;z<n;z++){
        map<string,int>zxc;
        int a,b;
        cin >> a >> b;
        string s; 
        cin >> s;
        string temp="";
        for(int i=0;i<b-1;i++){
            temp += s[i];
        }
        for(int i=b-1;i<s.size();i++){
            temp += s[i];
            zxc[temp] += 1;
            temp.erase(temp.begin());
        }
        map<string,int>::iterator it;
        int cnt = 0;
        for(it = zxc.begin();it!=zxc.end();it++){
            cnt++;
        }
        cout << cnt << endl;
    }
    
    return 0;
}