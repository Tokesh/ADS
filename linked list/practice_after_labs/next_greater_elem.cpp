class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        
        for(int i=0;i<nums1.size();i++){
            bool ok =false;
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==nums1[i]) ok = true;
                if(nums2[j] > nums1[i] && ok == true){
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if(ans.size() == i){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};