class Solution {
private:
    double solve(int idx, int k, vector<int>& nums,
                 vector<vector<double>>& dp) {
        if (idx < 0)
            return 0.0;
        if (k == 0) {
            return INT_MIN;
        }
        if (dp[idx][k] != -1.0)
            return dp[idx][k];
        double maxScore = 0;
        double sum = 0;
        for (int i = idx; i >= 0; i--) {
            sum += nums[i];
            maxScore = max(maxScore, (sum / (idx - i + 1)) +
                                         solve(i - 1, k - 1, nums, dp));
        }
        return dp[idx][k] = maxScore;
    }

public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        // Approach-1(Recursion-backtracking)
        //  int n=nums.size();
        //  vector<vector<double>> dp(n+1,vector<double>(k+1,-1.0));
        //  return solve(n-1,k,nums,dp);

        // Approach-2(Tabulation Mehod-Bottom up dyanmic programming)
        int n = nums.size();
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0));
        vector<double> prefixSum(n + 1, 0);

        // Calculate prefix sums
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Base case: dp[i][1] = average of the first i elements
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefixSum[i] / i;
        }

        // Fill the DP table
        for (int j = 2; j <= k; j++) { // For each partition count
            for (int i = 1; i <= n; i++) { // For each element in the array
                double maxScore = 0;
                for (int l = 1; l <= i; l++) { // Try partitioning at every possible point
                    double avg = (prefixSum[i] - prefixSum[l - 1]) / (i - l + 1);
                    maxScore = max(maxScore, dp[l - 1][j - 1] + avg);
                }
                dp[i][j] = maxScore;
            }
        }

        return dp[n][k];
    }
};