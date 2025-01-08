class Solution {
public:
    int solve(int idx, vector<int>& squares, int n, vector<vector<int>>& dp){
        if(n == 0) return 0;
        if(idx < 0) return INT_MAX;
        if(dp[idx][n]!=-1)return dp[idx][n];

        int take = INT_MAX;
        if(squares[idx] <= n){
            take = solve(idx, squares, n - squares[idx],dp);
            if(take != INT_MAX) take += 1;
        }

        int not_take = solve(idx - 1, squares, n, dp);

        return dp[idx][n]=min(take, not_take);
    }

    int numSquares(int n) {
        // vector<int> squares;
        // for(int i = 1; i * i <= n; i++){
        //     squares.push_back(i * i);
        // }

        // vector<vector<int>> dp(squares.size(),vector<int>(n+1,-1));
        // return solve(squares.size() - 1, squares, n,dp);

        //Approach-2(Tabulation-Bottom up dynamic programming)
        vector<int> squares;
        for(int i = 1; i * i <= n; i++){
            squares.push_back(i * i);
        }

        vector<vector<int>> dp(squares.size(),vector<int>(n+1));
        for(int i=0;i<squares.size();i++)dp[i][0]=0;

       // Initialize the first row (using only the first square)
        for(int j = 1; j <= n; j++) {
            if(j % squares[0] == 0) {
                dp[0][j] = j / squares[0];  // Minimum squares to reach j
            }
        }

        // Fill the dp table for remaining squares
        for(int i = 1; i < squares.size(); i++) {
            for(int j = 1; j <= n; j++) {
                int take = INT_MAX;
                if(squares[i] <= j) {
                    take = dp[i][j - squares[i]];
                    if (take != INT_MAX) {
                        take += 1;
                    }
                }
                int not_take = dp[i - 1][j];

                dp[i][j] = min(take, not_take);
            }
        }

        return dp[squares.size() - 1][n];
    }
};
