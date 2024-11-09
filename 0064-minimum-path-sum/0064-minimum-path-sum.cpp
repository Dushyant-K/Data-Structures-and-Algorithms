class Solution {
    private:
    int solve(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(m==0&&n==0)return grid[0][0];
        if(m<0||n<0)return INT_MAX;

        if(dp[m][n]!=-1)return dp[m][n];


        int top = solve(m-1,n,grid,dp);
        int left = solve(m,n-1,grid,dp);

        return dp[m][n]= min(top,left)+grid[m][n];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        //Approach-1(Memoization method-top Down Dynamic Programming)
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};