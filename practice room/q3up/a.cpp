#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int arr[1000];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int p = 2;
    long long int p_pow[1000];
    p_pow[0] = 1;
    for(int i=1;i<1000;i++){
        p_pow[i] = p*p_pow[i-1];
    }
    string j = "";
    for(int i=0;i<n;i++){
        long long int z=arr[i];
        if(i != 0) z -= arr[i-1];
        z /= p_pow[i];
        j += char(z+97);
    }
    cout << j;
    return 0;
}