#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(){
    int n,o=1000,x,y,z;
    int arr[100][100];
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                for(int k=0;k<n;k++){
                    if(k!=j && k!=i &&  (arr[i][j] + arr[j][k] + arr[k][i]) < o){
                        o = arr[i][j] + arr[j][k] + arr[k][i];;
                        x = i;
                        y = j;
                        z = k;
                    }
                }
            }
        }
    }
    cout << x+1 << ' ' << y + 1 << ' ' << z +1;

    return 0;
}