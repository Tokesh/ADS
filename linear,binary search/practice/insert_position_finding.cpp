class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,res=0;
        while(l <= r){
            int mid = (r+l) / 2;
            if(nums[mid] <= target){
                l = mid+1;
                res = mid;
            }else{
                r = mid-1;
            }
        }
        if(nums[res]<target) return res+1;
        return res;
    }
};