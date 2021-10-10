class Solution {
public:
    int numTrees(int n) {
     //indentification of this question is actually catalan numbers.
      vector<int>dp(n+1);
      dp[0]=1;//n=0 ==1
      dp[1]=1; //when n=1, only one structure is possible
       for(int i=2;i<=n;i++)
       {
           for(int j=0;j<i;j++)
               dp[i]+=dp[j]*dp[i-j-1];
       }
        return dp[n];
        
    }
};