#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int arr[100000];
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    if(n)
    int l=0,r=0;
    int mini=arr[0];
    int second_mini = max(arr[0],arr[1]);
    int second_mini_cnt = 0;
    if(second_mini == mini) second_mini_cnt++;
    int sumi = (arr[l] + arr[r]);
    for(int i=2;i<n;i++){
        long long int temp = sumi+arr[i];
        long long int temp_mini = min(arr[i], mini);
        
        if(arr[l] > mini){
            long long int temp1 = (temp * temp_mini);

        }
    }


    return 0;
}