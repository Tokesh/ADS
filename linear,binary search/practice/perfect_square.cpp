class Solution {
public:
    bool isPerfectSquare(int num) {
        bool ok = false;
        long long int l = 1,r=num,res = 1;
        while(l <= r){
            long long int mid = l+(r-l)/2;
            if(mid * mid > num){
                r = mid-1;
            }else if(mid * mid == num){
                return true;
                res = mid;
                ok = true;
            }else{
                l = mid+1;
            }
        }
        return false;
        
    }
};