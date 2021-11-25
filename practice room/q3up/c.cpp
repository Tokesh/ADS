#include <iostream>
using namespace std;
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int size = min(s1.size(),s2.size());
    int i =0;
    if(s1.size() < s2.size()) i = 0;
    else i = s1.size()-s2.size();
    while(size != 0){
        if(s1.substr(i,size) == s2.substr(0,size)){
            break;
        }
        i++;
        size--;
    }
    for(int i=size;i<s2.size();i++){
        s1 += s2[i];
    }
    cout << s1;
    return 0;
}