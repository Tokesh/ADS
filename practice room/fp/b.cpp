#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int main(){
    int a,b;
    cin >> a >> b;
    if(a==b){
        cout << 0;
        return 0;
    }
    queue<int>q;
    vector<int>d(25000, INF), p(25000);
    q.push(a);
    d[a] = 0;
    p[a] = -1;
    while(!q.empty() && d[b] == INF){
        int v = q.front();
        q.pop();
        int dec = v-1;
        if(d[dec] > d[v] + 1){
            q.push(dec);
            d[dec] = d[v] + 1;
            p[dec] = v;
        }
        int mult = v*2;
        if(mult > 20000) continue;
        if(d[mult] > d[v] + 1){
            q.push(mult);
            d[mult] = d[v] + 1;
            p[mult] = v;
        }
        /* cout << v << ' ' << mult << ' ' << dec << endl; */
    }
    cout << d[b] << endl;
    vector<int>res;
    for(int i=b;i!=-1;i=p[i]){
        res.push_back(i);
    }
    reverse(res.begin(),res.end());
    for(int i=1;i<res.size();i++){
        cout << res[i] << ' ' ;
    }
    return 0;
}