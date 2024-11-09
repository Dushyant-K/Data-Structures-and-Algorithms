class Solution {
    private:
    int solve(int m, int n,vector<vector<int>>& dp){
        //Base-cases
        if(m==0&&n==0)return 1;//Reached destination
        if(m<0||n<0)return 0;//There is no path because we have moved out of the grid

        //Checking if the problem has been solved before or not
        if(dp[m][n]!=-1)return dp[m][n];

        //Now we move either to the left or to the upwards direction
        int up = solve(m-1,n,dp);
        int left = solve(m,n-1,dp);

        return dp[m][n]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        //Approach-1(Memoization method-Top Down dynamic Programming Approach)
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};