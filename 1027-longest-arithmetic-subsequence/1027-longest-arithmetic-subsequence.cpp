class Solution {
    private:
    int solve(int idx, int prev1, int prev2, vector<int>& nums,vector<vector<vector<int>>>& dp){
        if(idx<0)return 0;
        if(dp[idx][prev1+1][prev2+1]!=-1)return dp[idx][prev1+1][prev2+1];

        //Not-take
        int not_take=solve(idx-1,prev1,prev2,nums,dp);

        //Take
        int take=0;
        if(prev1==-1){
            take=1+solve(idx-1,idx,prev2,nums,dp);
        }
        else if(prev2==-1){
            take=1+solve(idx-1,prev1,idx,nums,dp);
        }
        else if(nums[idx]-nums[prev2]==nums[prev2]-nums[prev1]){
            take=1+solve(idx-1,prev2,idx,nums,dp);
        }

        return dp[idx][prev1+1][prev2+1]=max(take,not_take);
    }
    int solve(int idx, int prevIdx, int diff, vector<int>& nums, vector<unordered_map<int, int>>& dp) {
        if (idx == nums.size()) return 0;

        // Check memoization
        if (dp[prevIdx].count(diff)) return dp[prevIdx][diff];

        // Option 1: Skip the current element
        int notTake = solve(idx + 1, prevIdx, diff, nums, dp);

        // Option 2: Take the current element if it forms an arithmetic sequence
        int take = 0;
        if (nums[idx] - nums[prevIdx] == diff) {
            take = 1 + solve(idx + 1, idx, diff, nums, dp);
        }

        // Memoize and return the result
        dp[prevIdx][diff] = max(take, notTake);
        return max(take, notTake);
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        //Approach-1(Memoization Method-Top down dynamic programming)
        // int n=nums.size();
        // if(n<=2)return n;
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        // return solve(n-1,-1,-1,nums,dp);

        //Approach-2(Different Approach)
        // int n = nums.size();
        // if (n <= 2) return n;

        // int maxLength = 2; // At least two elements form an arithmetic sequence
        // vector<unordered_map<int, int>> dp(n); // Memoization for each index and difference

        // // Try starting with every pair of elements as the first two in the subsequence
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         int diff = nums[j] - nums[i];
        //         maxLength = max(maxLength, 2 + solve(j + 1, j, diff, nums, dp));
        //     }
        // }
        // return maxLength;

        //Approach-3(Tabulation Method-Bottom up dynamic prigramming)
        int n=nums.size();
        if(n<=2)return n;

        int maxLength=2;
        vector<unordered_map<int,int>> dp(n);

         for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                int diff = nums[j] - nums[i];

                // If the difference exists for dp[i], extend the subsequence; otherwise, start a new one
                dp[j][diff] = dp[i].count(diff) ? dp[i][diff] + 1 : 2;

                // Update the maximum length
                maxLength = max(maxLength, dp[j][diff]);
            }
        }

        return maxLength;
    }
};