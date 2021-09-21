class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        vector<int>results{};
       while(left<right){
            int targetNum=numbers[left]+numbers[right];
            if(targetNum==target)return results={++left,++right};
            else if(targetNum<target)left++;
            else right--;
        }
        return results;
    }
};