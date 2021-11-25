//10305 - Ordering Tasks
#include <iostream>
using namespace std;

int n,m;
int arr[500][500];
bool a[500];
int k=0;
int queue[500];

void dfs(int v){
    if(a[v] == 1) return;
    for(int i=0;i<n;i++){
        if(arr[v][i] == 1){
            dfs(i);
        }
    }
    a[v] = 1;
    queue[k++] = v;
}

int main(){
    
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        if(a != 0 && b != 0){
            a--;
            b--;
            if(arr[b][a] != 1) arr[a][b] = 1;
        }else{
            break;
        }
    }
    for(int i=0;i<n;i++){
        dfs(i);
    }
    for(int i=0;i<k;i++){
        cout << queue[i] + 1 << ' ';
    }
    return 0;
}