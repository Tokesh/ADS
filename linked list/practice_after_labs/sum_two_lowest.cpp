#include <iostream>
#include <vector>
using namespace std;
long long int sumTwoSmallestNumbers(vector<int> numbers){
    long long int mini=100000000000000000;
    long long int second_mini=100000000000000000;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i] < mini){
            second_mini = mini;
            mini = numbers[i];
        }else if(second_mini > numbers[i]){
            second_mini = numbers[i];
        }
    }
    long long int temp = mini+second_mini;
    return temp;
}

int main(){
    vector<int>zxc;
    zxc.push_back(1);
    zxc.push_back(2);
    zxc.push_back(3);
    zxc.push_back(4);
    cout << sumTwoSmallestNumbers(zxc);

}