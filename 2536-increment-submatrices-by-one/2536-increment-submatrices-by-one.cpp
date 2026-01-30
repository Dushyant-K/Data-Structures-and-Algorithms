class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        //Approach-1(Marking approach-Learned on Leetcode Contest)
    // Step 1: Initialize a difference matrix of size (n+1)x(n+1)
    vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));

    // Step 2: Process each query and update the difference matrix
    for (const auto& query : queries) {
        int row1 = query[0], col1 = query[1];
        int row2 = query[2], col2 = query[3];

        // Add 1 to the top-left corner
        diff[row1][col1] += 1;

        // Subtract 1 from the cell right to the bottom-right corner (if within bounds)
        if (col2 + 1 < n) diff[row1][col2 + 1] -= 1;

        // Subtract 1 from the cell below the bottom-right corner (if within bounds)
        if (row2 + 1 < n) diff[row2 + 1][col1] -= 1;

        // Add 1 to the cell diagonally below and to the right of the bottom-right corner (if within bounds)
        if (row2 + 1 < n && col2 + 1 < n) diff[row2 + 1][col2 + 1] += 1;
    }

    // Step 3: Compute the prefix sum to construct the final matrix
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Calculate prefix sum
            mat[i][j] = diff[i][j];
            if (i > 0) mat[i][j] += mat[i - 1][j];
            if (j > 0) mat[i][j] += mat[i][j - 1];
            if (i > 0 && j > 0) mat[i][j] -= mat[i - 1][j - 1];
        }
    }

    return mat;
    }
};