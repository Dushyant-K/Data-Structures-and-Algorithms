class Solution {
    private:
    int solve(int n, int m,vector<vector<int>> obstacleGrid, vector<vector<int>>& dp){
        //Base-case
        if(n<0||m<0||obstacleGrid[n][m]==1)return 0;//There is no path
        if(n==0&&m==0)return 1;//Reached Destination(Edge casde is there that's why put it after checking for path)

        //Checking that if this subproblem has been solved before
        if(dp[n][m]!=-1)return dp[n][m];

        //Now we either move left or top wards
        int top = solve(n-1,m,obstacleGrid,dp);
        int left = solve(n,m-1,obstacleGrid,dp);

        return dp[n][m]=left+top;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //Approach-1(Memoization Method-Top Down Dynamic programming)
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,obstacleGrid,dp);
    }
};