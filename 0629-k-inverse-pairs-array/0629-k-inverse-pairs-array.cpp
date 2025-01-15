class Solution {
    int mod=1e9+7;
    private:
     int solve(int n, int k, vector<vector<int>>& dp) {
        // Base cases
        if (k < 0) return 0;               // No negative inverse pairs possible
        if (n == 0) return k == 0 ? 1 : 0; // Only one valid array when k == 0
        
        // Check if already calculated
        if (dp[n][k] != -1) return dp[n][k];

        // Recursive case: Add the nth element at every possible position
        int result = 0;
        for (int i = 0; i <= min(k, n - 1); ++i) {
            result = (result + solve(n - 1, k - i, dp)) % mod;
        }

        return dp[n][k] = result;
    }
public:
    int kInversePairs(int n, int k) {
        //Approach-1(Memoizaion Method- Top Down dynamic programming)
        // vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        // return solve(n, k, dp);

        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                int result=0;
                for(int pairs=0;pairs<=min(j,i-1);pairs++){
                    result=(result+dp[i-1][j-pairs])%mod;
                }
                dp[i][j]=result;
            }
        }
        return dp[n][k];
    }
};