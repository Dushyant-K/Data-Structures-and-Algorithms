class Solution {
    private:
    int solve(int idx, vector<int>& dp){
        if(idx==0)return 1;

        if(dp[idx]!=-1)return dp[idx];

        int left = solve(idx-1,dp);
        int right=0;
        if(idx!=1)
        right = solve(idx-2,dp);

        return dp[idx] = left+right;
    }
public:
    int climbStairs(int n) {
      //Approach-1(Memoiztion Method)
    //   vector<int> dp(n+1,-1);
    //   return solve(n,dp);  

      //Approach-2(Tabulation Method)
    //   vector<int> dp(n+1,-1);
    //   dp[0]=1;
    //   dp[1]=1;
    //   for(int i=2;i<=n;i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    //   }
    //   return dp[n];

      //Now finally we do the space optimiztion
      int prev2=1;
      int prev1=1;
      for(int i=2;i<=n;i++){
        int curr = prev1+prev2;
        prev2 = prev1;
        prev1=curr;
      }
      return prev1;
    }
};