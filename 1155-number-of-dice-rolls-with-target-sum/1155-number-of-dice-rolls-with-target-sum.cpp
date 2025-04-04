class Solution {
    int mod=1e9+7;
    private:
    int solve(int n, int k, int target, vector<vector<int>>& dp){
        if(n==0){
            return target==0;
        }
        if(dp[n][target]!=-1)return dp[n][target];

        int ways=0;
        for(int i=1;i<=k;i++){
            if(i<=target){
                ways=(ways+solve(n-1,k,target-i,dp))%mod;
            }
            else break;
        }
        return dp[n][target]=ways;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
    //Approach-1(Memoization Method-top down dynamic programming)
    //    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
    //    return solve(n,k,target,dp); 

    //Approach-2(Tabulation Method-Bottom up dynamic programming)
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        for(int targets=0;targets<=target;targets++){
            int ways=0;
            for(int j=1;j<=k;j++){
                if(j<=targets){
                    ways=(ways+dp[i-1][targets-j])%mod;
                }
                else break;
            }
            dp[i][targets]=ways;
        }
    }

    return dp[n][target];
    }
};