#include <iostream>
using namespace std;
int arr[100000];

void quicksort(int l, int r){
    int i = l;
    int j = r;
    int p = arr[l + (r-l)/2];
    while(i <j){
        while(arr[i] < p) i++;
        while(arr[j] > p) j--;
        if(i <= j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(l < j) quicksort(l, j);
    if(i < r) quicksort(i, r);
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int temp[100000], j = 0;
    int cnt=0;
    quicksort(0, n-1);
    if(n == 1){
        cout << 1;
        return 0;
    }
    for(int i=1;i<n;i++){
        if(arr[i] != arr[i-1]){
            cnt++;
            temp[j++] = arr[i];
        }
    }
    if(arr[n-1] != temp[j]) cnt++;
    if(n != 0 && cnt == 0) cnt++;
    cout << cnt;
    return 0;
}