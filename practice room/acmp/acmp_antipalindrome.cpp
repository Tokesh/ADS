#include <iostream>
using namespace std;

bool eq(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] != s[0]) return false;
    }
    return true;
}


bool pal_c(string s){
    for(int i=0;i<s.size()/2+1;i++){
        if(s[i] != s[s.size()-i-1]) return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    int k = s.size();
    if(eq(s)){
        cout <<"NO SOLUTION";
        return 0;
    }
    while (k!=0){
        bool res = pal_c(s.substr(0,k));
        if(res == false){
            cout << s.substr(0,k);
            return 0;
        }
        k--;
    }
    return 0;
}