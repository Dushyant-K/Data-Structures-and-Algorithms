class Solution {
    private:
    int solve(int idx, int prev, int k, vector<int>& nums, vector<vector<vector<int>>>& dp){
        if (k < 0) return INT_MIN; // Invalid case
        if (idx < 0) return 0;     // Base case: no more elements
        
        if (dp[idx][prev + 1][k] != -1) return dp[idx][prev + 1][k];
        
        // Take the current element
        int take = 0;
        if (prev == -1 || nums[idx] == nums[prev]) {
            take = 1 + solve(idx - 1, idx, k, nums, dp);
        } else {
            take = 1 + solve(idx - 1, idx, k - 1, nums, dp);
        }
        
        // Don't take the current element
        int not_take = solve(idx - 1, prev, k, nums, dp);
        
        // Memoize and return the result
        return dp[idx][prev + 1][k] = max(take, not_take);
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        // //Approach-1(Memoization Method-Top down dynamic programing)
        // int n = nums.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        // return solve(n - 1, -1, k, nums, dp);

        //Approach-2(Tabulation Method-Bottom up dynamic programming)
    //    int n = nums.size();
    //     if (n == 0) return 0;

        // Step 1: Coordinate Compression (if needed)
        // vector<int> compressed = nums;
        // sort(compressed.begin(), compressed.end());
        // compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

        // unordered_map<int, int> compressIndex;
        // for (int i = 0; i < compressed.size(); ++i) {
        //     compressIndex[compressed[i]] = i;
        // }

        // int m = compressed.size(); // Number of unique elements

        // // Step 2: Dynamic Programming with Compression
        // vector<vector<int>> dp(k + 1, vector<int>(m, 0)); // dp[remaining][value_index]

        // int result = 0;

        // for (int num : nums) {
        //     int index = compressIndex[num]; // Compressed index of current number

        //     for (int remaining = k; remaining >= 0; --remaining) {
        //         // Continuing the same group
        //         dp[remaining][index] = max(dp[remaining][index], 1 + dp[remaining][index]);

        //         // Starting a new group
        //         if (remaining > 0) {
        //             for (int prevIndex = 0; prevIndex < m; ++prevIndex) {
        //                 if (prevIndex != index) {
        //                     dp[remaining][index] = max(dp[remaining][index], 1 + dp[remaining - 1][prevIndex]);
        //                 }
        //             }
        //         }

        //         // Update global result
        //         result = max(result, dp[remaining][index]);
        //     }
        // }

        // return result;

        //Approach-3
        int n = nums.size();

        vector<vector<int>> dp (n, vector<int> (k + 1));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            for (int j = 0; j < i; j++)
                if (nums[i] == nums[j])
                    dp[i][0] = max(dp[i][0], dp[j][0] + 1);
        }
        
        for (int i = 1; i <= k; i++) {
            int prev_row_max = 0;
            unordered_map<int, int> max_sub_size;
            for (int j = 0; j < n; j++) {
                dp[j][i] = max(dp[j][i], max_sub_size[nums[j]] + 1);
                dp[j][i] = max(dp[j][i], prev_row_max + 1);
                
                max_sub_size[nums[j]] = dp[j][i];
                prev_row_max = max(prev_row_max, dp[j][i - 1]);
            }
        }
        
        int res = 0;
        for (int i = 0; i <= k; i++)
            for (int j = 0; j < n; j++)
                res = max(res, dp[j][i]);
        return res;
    }
};