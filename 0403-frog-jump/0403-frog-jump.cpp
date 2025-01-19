class Solution {
    private:
    bool canCrossHelper(vector<int>& stones, int currentIndex, int lastJump, vector<vector<int>>& dp, unordered_map<int, int>& stoneIndex) {
    // If the frog has reached the last stone
    if (currentIndex == stones.size() - 1) {
        return true;
    }

    // If the current state is already computed
    if (dp[currentIndex][lastJump] != -1) {
        return dp[currentIndex][lastJump];
    }

    // Try jumps of k-1, k, and k+1 units
    for (int jump = lastJump - 1; jump <= lastJump + 1; ++jump) {
        if (jump > 0) { // Only consider positive jumps
            int nextPos = stones[currentIndex] + jump;

            // Check if the next position is a stone
            if (stoneIndex.count(nextPos)) {
                int nextIndex = stoneIndex[nextPos];
                if (canCrossHelper(stones, nextIndex, jump, dp, stoneIndex)) {
                    return dp[currentIndex][lastJump] = 1;
                }
            }
        }
    }

    return dp[currentIndex][lastJump] = 0;
}
public:
    bool canCross(vector<int>& stones) {
    int n = stones.size();
    vector<vector<int>> dp(n, vector<int>(n, -1)); // DP table to store results
    unordered_map<int, int> stoneIndex; // Map stone position to its index

    for (int i = 0; i < n; ++i) {
        stoneIndex[stones[i]] = i;
    }

    if (stones[1] != 1) {
        return false; // If the first jump isn't possible
    }

    return canCrossHelper(stones, 0, 0, dp, stoneIndex);
    }
};