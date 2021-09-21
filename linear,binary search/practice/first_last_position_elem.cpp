class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return{-1,-1};
        // left side
        int l2=0,r2=nums.size()-1,res_l=0;
        while(l2 <= r2){
            int mid=l2+(r2-l2)/2;
            if(nums[mid] >= target){
                r2=mid-1;
                res_l = mid;
            }else{
                l2 = mid+1;
            }
        }
        // right side
        int l1=0,r1=nums.size()-1,res_r=0;
        while(l1 <= r1){
            int mid=l1+(r1-l1)/2;
            if(nums[mid] <= target){
                res_r = mid;
                l1 = mid+1;
            }else{
                r1 = mid-1;
            }
        }
        
        if(nums[res_l] != target && nums[res_r] != target) return {-1,-1};
        return {res_l,res_r};
    }
};