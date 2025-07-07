class Solution {
public:
    bool check(int idx, int curr, vector<int>& arr, int target, int n, vector<vector<int>>& dp) {
        if (idx == n) return curr == target;

        if (dp[idx][curr] != -1) return dp[idx][curr];

        // Pick
        if (curr + arr[idx] <= target && check(idx + 1, curr + arr[idx], arr, target, n, dp)) {
            return dp[idx][curr] = true;
        }

        // Not Pick
        if (check(idx + 1, curr, arr, target, n, dp)) {
            return dp[idx][curr] = true;
        }

        return dp[idx][curr] = false;
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += arr[i];

        if (k > sum) return false;  // Optimization

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return check(0, 0, arr, k, n, dp);
    }
};
