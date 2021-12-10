#include <iostream>
#include <vector>
using namespace std;
int main(){
    int arr[100000];
    int n, sumi = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sumi += arr[i];
    }
    int i = 0, j = n-1;
    //left
    while(true){
        if(sumi - arr[i] < sumi){
            i++;
            sumi -= arr[i];
        }else{
            break;
        }
    }
    //right
    while(true){
        if(sumi - arr[j] < sumi){
            j--;
            sumi -= arr[j];
        }else{
            break;
        }
    }
    cout << abs(sumi);
    return 0;
}