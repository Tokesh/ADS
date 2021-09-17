#include <iostream>
#include <vector>
using namespace std;
int sumTwoSmallestNumbers(vector<int> numbers){
    long long int mini=0;
    long long int second_mini=0;
    
    cout << "ZXC";
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
    cout << zxc.size();
    sumTwoSmallestNumbers(zxc);

}