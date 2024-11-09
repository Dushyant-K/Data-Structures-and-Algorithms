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
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,dp);

        //Approach-2(Tabulation Method)
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)dp[i][j]=1;
                else{
                    int up=0,left=0;
                    if(i>0)up = dp[i-1][j];
                    if(j>0)left = dp[i][j-1];

                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};