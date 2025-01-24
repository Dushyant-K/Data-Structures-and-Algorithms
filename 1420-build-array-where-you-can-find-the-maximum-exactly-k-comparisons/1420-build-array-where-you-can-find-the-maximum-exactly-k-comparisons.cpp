class Solution {
    int mod=1e9+7;
    private:
    int solve(int n, int prev, int k, int m, vector<vector<vector<int>>>& dp){
        if(n==0){
            return k==0?1:0;
        }
        if(dp[n][prev][k]!=-1)return dp[n][prev][k];

        int count=0;
        for(int i=1;i<=m;i++){
            if(i>prev&&k>0)count=(count+solve(n-1,i,k-1,m,dp))%mod;
            else if(i<=prev)count=(count+solve(n-1,prev,k,m,dp))%mod;
        }
        return dp[n][prev][k]=count;
    }
public:
    int numOfArrays(int n, int m, int k) {
        //Approach-1(Memoization Method-Top Down dynamic programming)
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return solve(n,0,k,m,dp);
    }
};