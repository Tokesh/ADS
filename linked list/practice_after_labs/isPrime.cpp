#include <iostream>
using namespace std;

int arr[100000002];
//good solution but can take more memory than casual
//underline nice time code from codewars
bool isPrime(int n){
    if(n < 2) return false;
    for(int i=2;i*i <= n; i++){
        if(arr[i] == 0){
            int k = i;
            while(k+i <= n){
                k += i;
                arr[k] = 1;
            }
        }
    }
    if(arr[n] == 0) return true;
    return false;
}

int main(){
    int n;
    cin >> n;

}



// Best time CODEWARS
/* bool isPrime(int num) {
   
  if(num==2 || num ==3 || num ==5) 
   return true;
  
  else if(num <=1 || num % 2 ==0 || num % 3 ==0) 
   return false;
  
  else
  {
    for(int i=5; i<=sqrt(num); i+=6 )
     if( (num % i==0) || (num % (i+2) == 0)) return false;
    
    return true;
  
  }
  
  
} */
/* 
bool isPrime(int n){
    if(n < 2 ) return false;    
    if(n==2) return true;
    if(n%2==1){
      for(int i=2;i*i<=n;i++){
        if(n % i == 0) return false;
      }
    }else{
      return false;
    }
    return true;
} */