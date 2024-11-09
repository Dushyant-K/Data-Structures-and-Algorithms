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
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,grid,dp);

        //Approach-2(Tabulation method-Bottom Up Dynamic Programming Approach)
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)dp[0][0]=grid[0][0];
                else{
                    int top = INT_MAX;
                    int left = INT_MAX;
                    if(i>0)top = dp[i-1][j];
                    if(j>0)left = dp[i][j-1];

                    dp[i][j] = grid[i][j]+min(top,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};