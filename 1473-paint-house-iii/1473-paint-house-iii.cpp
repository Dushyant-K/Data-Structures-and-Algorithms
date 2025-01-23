class Solution {
    private:
     int solve(int idx, int prevColor, int neighbourhood, vector<int>& house, vector<vector<int>>& cost, int m, int n, int target, vector<vector<vector<int>>>& dp) {
        // Base Case
        if (idx == m) {
            return neighbourhood == target ? 0 : INT_MAX;
        }

        // Check Memoization
        if (dp[idx][prevColor][neighbourhood] != -1) {
            return dp[idx][prevColor][neighbourhood];
        }

        int minCost = INT_MAX;

        if (house[idx] == 0) { // House is not painted
            for (int i = 0; i < n; i++) {
                int newNeighborhood = (prevColor == i + 1) ? neighbourhood : neighbourhood + 1;
                if (newNeighborhood > target) continue; // Prune invalid cases
                
                int result = solve(idx + 1, i + 1, newNeighborhood, house, cost, m, n, target, dp);
                if (result != INT_MAX) {
                    minCost = min(minCost, cost[idx][i] + result);
                }
            }
        } else { // House is already painted
            int newNeighborhood = (prevColor == house[idx]) ? neighbourhood : neighbourhood + 1;
            if (newNeighborhood <= target) {
                minCost = solve(idx + 1, house[idx], newNeighborhood, house, cost, m, n, target, dp);
            }
        }

        return dp[idx][prevColor][neighbourhood] = minCost;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        //Approach-1(Memoization Method-Top Down dynamic programming)
        // Initialize Memoization Table
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
        
        int result = solve(0, 0, 0, houses, cost, m, n, target, dp);
        return result == INT_MAX ? -1 : result; // Return -1 if no valid painting scheme
    }
};