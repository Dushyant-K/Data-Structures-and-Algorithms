class Solution {
    private:
    int solve(int n, int m,vector<vector<int>> obstacleGrid, vector<vector<int>>& dp){
        //Base-case
        if(n==0&&m==0)return 1;//Reached Destination
        if(n<0||m<0||obstacleGrid[n][m]==1)return 0;//There is no path

        //Checking that if this subproblem has been solved before
        if(dp[n][m]!=-1)return dp[n][m];

        //Now we either move left or top wards
        int top = solve(n-1,m,obstacleGrid,dp);
        int left = solve(n,m-1,obstacleGrid,dp);

        return dp[n][m]=left+top;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Approach-1(Memoization Method-Top Down Dynamic programming)
        // int n = obstacleGrid.size();
        // int m = obstacleGrid[0].size();
        // if(obstacleGrid[0][0]==1)return 0;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,obstacleGrid,dp);

        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        // int n = obstacleGrid.size();
        // int m = obstacleGrid[0].size();
        // if(obstacleGrid[0][0]==1)return 0;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(i==0&&j==0)dp[0][0]=1;
        //         else{
                    
        //             int top = 0;
        //             int left=0;
        //             if(i>0&&obstacleGrid[i][j]!=1)top = dp[i-1][j];
        //             if(j>0&&obstacleGrid[i][j]!=1)left = dp[i][j-1];

        //             dp[i][j]=top+left;
        //         }
        //     }
        // }
        // return dp[n-1][m-1];

        //Approach-3(Space optimization)
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> prev(m,-1);
        if(obstacleGrid[0][0]==1)return 0;

        for(int i=0;i<n;i++){
            vector<int> temp(m);
            for(int j=0;j<m;j++){
                if(i==0&&j==0){
                    prev[0]=1;
                    temp[0]=1;
                }
                else{
                    int top=0,left=0;
                    if(i>0&&obstacleGrid[i][j]!=1)top = prev[j];
                    if(j>0&&obstacleGrid[i][j]!=1)left = temp[j-1];

                    temp[j]=top+left;
                }
            }
            prev = temp;
        }
        return prev[m-1];
    }
};