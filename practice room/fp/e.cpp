#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<pair<int,int>>z;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        z.push_back(cin>>x);
    }
    return 0;
}