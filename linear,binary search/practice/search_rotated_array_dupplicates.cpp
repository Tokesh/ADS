class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mini = 100000,mini_ind=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= mini){
                mini = nums[i];
                mini_ind = i;
            }
        }
        bool ok = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > mini){
                ok = true;
            }
            if(ok == true && mini == nums[i]){
                mini_ind = i;
                break;
            }
        }
        int l1=mini_ind,r1=nums.size()-1,res=-1;
        while(l1<=r1){
            int mid = (l1+r1)/2;
            if(nums[mid]>target){
                r1=mid-1;
            }else if(nums[mid] < target){
                l1 = mid+1;
            }else{
                return true;
            }
        }
        if(res==-1){
            int l2=0,r2=mini_ind-1;
            while(l2<=r2){
                int mid = (l2+r2)/2;
                if(nums[mid]>target){
                    r2=mid-1;
                }else if(nums[mid] < target){
                    l2 = mid+1;
                }else{
                    return true;
                }
            }
        }
        return false;
    }
};