class Solution {
    private:
    int mod=1e9+7;
    int solve(int n, int absent, int late, vector<vector<vector<int>>>& dp){
        if(n==0)return 1;
        if(dp[n][absent][late]!=-1)return dp[n][absent][late];

        int result=0;
        result=(result+solve(n-1,absent,0,dp))%mod;

        if(absent<1)result=(result+solve(n-1,absent+1,0,dp))%mod;

        if(late<2)result=(result+solve(n-1,absent,late+1,dp))%mod;

        return dp[n][absent][late]=result;
    }
public:
    int checkRecord(int n) {
        //Approach-1(Memoization Method- Top Down dynamic programming)
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(n,0,0,dp);
    }
};