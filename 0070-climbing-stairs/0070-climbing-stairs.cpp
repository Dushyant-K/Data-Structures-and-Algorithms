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
      vector<int> dp(n+1,-1);
      return solve(n,dp);  
    }
};