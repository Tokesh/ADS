#include <iostream>
using namespace std;
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int i =0;
    int cnt=0,maxi =0;
    while(i< s2.size()-s1.size()+1){
        if(s2.substr(i,s1.size()) == s1){
            cnt += 1;
            maxi = max(cnt,maxi);
            i += s1.size()-1;
        }else{
            cnt = 0;
        }
        i += 1;
    }
    cout << maxi;
    return 0;
}