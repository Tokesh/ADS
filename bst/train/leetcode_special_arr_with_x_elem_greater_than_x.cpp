class Solution {
public:
   
    int count (vector<int>&nums,int x)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=x)
            {
                cnt++;
            }
        }
        
        return cnt;
    }
    
    int specialArray(vector<int>& nums) 
    {
        /*
        [0,4,3,0,4]
        
        0 1 2 3 4
        */
        
        // create a search space
        int start=0;
        int end= 1e3+5;
      
        
        while(start<=end)
        {
            int middle=(start+end)/2;
            int cnt = count(nums,middle);
            if(cnt==middle)
            {
                return middle;
            }
            else if(cnt>middle)
            {
                start = middle+1;
            }
            else end = middle-1;
        }
        
        return -1;
        
    }
};