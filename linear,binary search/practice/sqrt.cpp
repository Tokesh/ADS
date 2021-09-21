class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        long long int l = 1, r = x, res=1;
        while(l <= r){
            long long int mid = (r+l) / 2;
            if(mid * mid > x){
                r = mid-1;
            }else{
                res = mid;
                l = mid+1;
            }
        }
        return res;
    }
};