class Solution {
    int mod = 1e9 + 7;

private:
     int solve(int cuts, int startRow, int endRow, int startCol, int endCol,
              vector<vector<int>>& prefixSum, int k) {
        if (cuts == k - 1) {
            return prefixSum[endRow + 1][endCol + 1] - prefixSum[startRow][endCol + 1] -
                   prefixSum[endRow + 1][startCol] + prefixSum[startRow][startCol] > 0;
        }

        int horizontal = 0, vertical = 0;

        // Horizontal cuts
        for (int i = startRow; i < endRow; i++) {
            int top = prefixSum[i + 1][endCol + 1] - prefixSum[startRow][endCol + 1] -
                      prefixSum[i + 1][startCol] + prefixSum[startRow][startCol];
            if (top > 0) {
                horizontal = (horizontal +
                              solve(cuts + 1, i + 1, endRow, startCol, endCol, prefixSum, k)) %
                             mod;
            }
        }

        // Vertical cuts
        for (int j = startCol; j < endCol; j++) {
            int left = prefixSum[endRow + 1][j + 1] - prefixSum[startRow][j + 1] -
                       prefixSum[endRow + 1][startCol] + prefixSum[startRow][startCol];
            if (left > 0) {
                vertical = (vertical +
                            solve(cuts + 1, startRow, endRow, j + 1, endCol, prefixSum, k)) %
                           mod;
            }
        }

        return (horizontal + vertical) % mod;
    }

public:
    int ways(vector<string>& pizza, int k) {
        // Approach-1(Recursion backtracking)
         int n = pizza.size(), m = pizza[0].size();

        // Precompute prefix sum for apple counts
        vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                prefixSum[i][j] = (pizza[i][j] == 'A') + prefixSum[i + 1][j] +
                                  prefixSum[i][j + 1] - prefixSum[i + 1][j + 1];
            }
        }

        return solve(0, 0, n - 1, 0, m - 1, prefixSum, k);
    }
};