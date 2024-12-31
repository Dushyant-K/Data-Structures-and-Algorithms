class Solution {
    int n;
public:
    int solve(int idx, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (idx == n) {
            return 0;
        }
        if (dp[idx] != -1) return dp[idx];

        // Single-day pass
        int single = costs[0] + solve(idx + 1, days, costs, dp);
        
        // 7-day pass
        int i = idx;
        while (i < n && days[i] - days[idx] < 7) i++;
        int week = costs[1] + solve(i, days, costs, dp);
        
        // 30-day pass
        int j = idx;
        while (j < n && days[j] - days[idx] < 30) j++;
        int month = costs[2] + solve(j, days, costs, dp);
        
        return dp[idx] = min({single, week, month});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        vector<int> dp(n + 1, -1); // DP array of size n
        return solve(0, days, costs, dp);
    }
};
