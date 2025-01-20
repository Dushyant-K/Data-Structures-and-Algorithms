class Solution {
    private:
       int solve(int rIdx, int kIdx, string& ring, string& key, int n, vector<vector<int>>& dp) {
        if (kIdx == key.size()) return 0; // If the key is complete

        if (dp[rIdx][kIdx] != -1) return dp[rIdx][kIdx]; // Return cached result

        int minSteps = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (ring[i] == key[kIdx]) {
                // Calculate distance clockwise and anti-clockwise
                int dist = abs(i - rIdx);
                dist = min(dist, n - dist);

                // Recur for the next key character
                int steps = dist + solve(i, kIdx + 1, ring, key, n, dp);
                minSteps = min(minSteps, steps);
            }
        }

        return dp[rIdx][kIdx] = minSteps + 1; // Add 1 for pressing the button
    }
public:
    int findRotateSteps(string ring, string key) {
        //Approach-1(Memoization Method-Top Down dynamic programming)
        int n = ring.size();
        vector<vector<int>> dp(n, vector<int>(key.size(), -1)); // Memoization table
        return solve(0, 0, ring, key, n, dp);
    }
};