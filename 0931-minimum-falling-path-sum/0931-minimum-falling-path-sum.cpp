class Solution {
    private:
    int solve(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(dp[row][col]!=-1)return dp[row][col];
        //Base-cases
        if(row==matrix.size()-1)return matrix[row][col];//Reached the destination

        int left=INT_MAX, right=INT_MAX;
        if(col>0)left=solve(row+1,col-1,matrix,dp);
        int down = solve(row+1,col,matrix,dp);
        if(col<matrix[0].size()-1)right = solve(row+1,col+1,matrix,dp);

        return dp[row][col]=matrix[row][col]+min(left,min(down,right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //Approach-1(Memoization Method(Top Down Dynamic programming))
        // int m = matrix.size();
        // int n = matrix[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));

        // int mini=INT_MAX;
        // for(int i=0;i<n;i++){
        //     mini = min(mini,solve(0,i,matrix,dp));
        // }
        // return mini;

        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        // int m = matrix.size();
        // int n = matrix[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // //Base-case
        // for(int i=0;i<n;i++){
        //     dp[m-1][i] = matrix[m-1][i];
        // }
        // for(int i=m-2;i>=0;i--){
        //     for(int j=0;j<n;j++){
        //         int left = INT_MAX, right = INT_MAX;
        //         if(j>0)left = dp[i+1][j-1];
        //         int down = dp[i+1][j];
        //         if(j<n-1)right = dp[i+1][j+1];

        //         dp[i][j] = matrix[i][j]+min(left,min(down,right));
        //     }
        // }
        // int mini = INT_MAX;
        // for(int i=0;i<n;i++){
        //     mini = min(mini,dp[0][i]);
        // }
        // return mini;

        //Approach-3(Space optimization)
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n,-1);
        //base-case
        for(int i=0;i<n;i++){
            prev[i] = matrix[n-1][i];
        }

        for(int i=m-2;i>=0;i--){
            vector<int> temp(n,-1);
            for(int j=0;j<n;j++){
                int left=INT_MAX, right = INT_MAX;
                if(j>0)left = prev[j-1];
                int down = prev[j];
                if(j<n-1)right = prev[j+1];

                temp[j] = matrix[i][j]+min(left,min(down,right));
            }
            prev = temp;
        }

        //Now finding out the mini
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,prev[i]);
        }
        return mini;
    }
};