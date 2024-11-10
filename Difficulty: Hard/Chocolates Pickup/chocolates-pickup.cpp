//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    // Function to find the maximum chocolates that can be collected recursively
int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    // Check if the positions (j1, j2) are valid
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9; // A very large negative value to represent an invalid position

    // Base case: If we are at the last row, return the chocolate at the positions (j1, j2)
    if (i == n - 1) {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    // If the result for this state is already computed, return it
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;
    
    // Try all possible moves (up, left, right) for both positions (j1, j2)
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            int ans;
            
            if (j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            
            // Update the maximum result
            maxi = max(maxi, ans);
        }
    }
    
    // Store the maximum result for this state in dp
    return dp[i][j1][j2] = maxi;
}
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // Approach-1(Memoization Method-Top down dynamic programming)
        // Create a 3D DP array to store computed results
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        // Call the recursive utility function to find the maximum chocolates starting from the first row
        return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends