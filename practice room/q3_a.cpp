#include <iostream>
using namespace std;
int main(){
    string s; 
    cin >> s;
    int n = s.size(), cnt = 0;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n && j + i < n;j++){
            
            string s1 = s.substr(0,i);
            string s2 = s.substr(i,j);
            string s3 = s.substr(j+i,n);
            if(s1 + s2 + s3 == s && s1 + s3 == s2 + s3){
                cnt++;
            }
            cout << s1 << ' ' << s2 << ' ' << s3 << endl;
        }
    }
    cout << cnt;
    return 0;
}