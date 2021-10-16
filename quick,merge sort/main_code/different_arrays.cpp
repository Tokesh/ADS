#include <iostream>
using namespace std;


void quicksort(int l, int r, int *arr){
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
    if(l < j) quicksort(l, j, arr);
    if(i < r) quicksort(i, r, arr);
}

int main(){
    int arr1[100000];
    int arr2[100000];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr1[i];
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> arr2[i];
    }
    quicksort(0, n-1, arr1);
    quicksort(0, k-1, arr2);
    int temp1[100000], j1 = 0;
    int temp2[100000], j2 = 0;

    for(int i=0;i<n;i++){
        if(arr1[i] != arr1[i-1]){
            temp1[j1++] = arr1[i];
        }
    }
    for(int i=0;i<k;i++){
        if(arr2[i] != arr2[i-1]){
            temp2[j2++] = arr2[i];
        }
    }
    for(int i=0;i<max(j1,j2);i++){
        if(temp1[i] != temp2[i]){
            cout <<"NO";
            return 0;
        }
    }
    cout <<"YES";
    return 0;
}