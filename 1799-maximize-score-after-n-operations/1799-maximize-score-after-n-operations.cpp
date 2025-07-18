class Solution {
private:
    int helper(int op, int mask, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if(op > n / 2) return 0;
        if(dp[op][mask]!=-1)return dp[op][mask];

        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) continue;
            for(int j = i + 1; j < n; j++) {
                if(mask & (1 << j)) continue;

                int value = op*__gcd(nums[i], nums[j]) + helper(op + 1, mask | (1 << i) | (1 << j), nums, n,dp);
                maxi = max(maxi, value);
            }
        }

        return dp[op][mask]=maxi;
    }

public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n/2+1,vector<int>(1<<n+1,-1));
        return helper(1, 0, nums, n,dp);  // op starts from 1 not 0 if using n/2 base
    }
};
