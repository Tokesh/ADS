#include <iostream>
#define INF 1000000000
using namespace std;


int main() {
    int n, s ,t,i,j,k;
    cin >> n >> s >> t;
    s--;
    t--;
    int a[n][n];
   
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j] == -1) a[i][j] = 1000000000;
        }
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                if (a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
        }
    }
    if(a[s][t] < INF){
        cout << a[s][t];
    }
    else cout << -1;

    return 0;
}