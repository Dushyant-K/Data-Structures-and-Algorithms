class Solution {
    private:
    // Function to find the minimum path sum recursively with memoization
int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle, int n,
                       vector<vector<int> > &dp) {
    // If the result for this cell is already calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If we're at the bottom row, return the value of the current cell
    if (i == n - 1)
        return triangle[i][j];

    // Calculate the sum of two possible paths: going down and going diagonally
    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

    // Store the minimum of the two paths in the dp table and return it
    return dp[i][j] = min(down, diagonal);
}
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //Approach-1(Memoiztion method-Top Down Dynamic Programming)
        int n = triangle.size();
        // Create a memoization table to store computed results
    vector<vector<int> > dp(n, vector<int>(n, -1));
    // Call the recursive function to find the minimum path sum
    return minimumPathSumUtil(0, 0, triangle, n, dp);
    }
};