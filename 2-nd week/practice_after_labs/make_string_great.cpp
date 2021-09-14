#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char>zxc;
    for(int i=0;i<s.size();i++){
        if(s[i] >= 65 && s[i] <= 90){
            char x = s[i] + 32;
            if(zxc.size() >= 1 &&zxc.top() == x){
                zxc.pop();
            }else{
                zxc.push(s[i]);
            }
        }else if(s[i] >= 97 && s[i] <= 122){
            char x = s[i] - 32;
            if(zxc.size() >= 1 && zxc.top() == x){
                zxc.pop(); 
            }else{
                zxc.push(s[i]);
            }
        }
    }
    string j="";
    while(!zxc.empty()){
        j+=zxc.top();
        zxc.pop();
    }
    string final_ans="";
    for(int i=j.size()-1;i>=0;i--){
        final_ans += j[i];
    }
    cout << final_ans;
    return 0;
}