#include <iostream>
#include <map>
using namespace std;
int main(){
    map<int,int>zxc;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        zxc[x]+=1;
    }
    int maxi=-100000,second_maxi=-100000;
    map<int,int>::iterator it;
    for(it=zxc.begin();it!=zxc.end();it++){
        if(it->first > maxi){
            second_maxi = maxi;
            maxi = it->first;
        }else if(it->first > second_maxi){
            second_maxi = it->first;
        }
    }
    cout << second_maxi;
    return 0;
}