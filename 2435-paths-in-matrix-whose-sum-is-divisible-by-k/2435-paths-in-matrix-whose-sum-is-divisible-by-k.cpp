class Solution {
public:
    int solve(int row, int col, int m, int n, vector<vector<int>>& grid, int sum, int k, vector<vector<vector<int>>>& dp){
        if(row<0||row>=n||col<0||col>=m)return 0;
        if(row==n-1&&col==m-1){
            sum = sum+grid[row][col];
            if(sum%k==0)return 1;
            return 0;
        }

        if(dp[row][col][sum]!=-1)return dp[row][col][sum];

        //Exploring paths
        //Right
        int right = solve(row,col+1,m,n,grid,sum+grid[row][col],k,dp);
        //Down
        int left = solve(row+1,col,m,n,grid,sum+grid[row][col],k,dp);

        return dp[row][col][sum]=left+right;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        //Approach-1(Recursion with backtracking and dynamic programming approach)
        // int n = grid.size();
        // int m = grid[0].size();

        // int sum = 0;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         sum+=grid[i][j];
        //     }
        // }
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(sum+1,-1)));
        // return solve(0,0,m,n,grid,0,k,dp);


        //Approach-2(Tabulation Method)
        const int m=grid.size(), n=grid[0].size();
        const int mod=1e9+7;
        int dp[2][n][k];
        memset(dp, 0, sizeof(dp));
        dp[0][0][(k-grid[0][0]%k)%k]=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                const int x=grid[i][j];
                for(int r=0; r<k; r++){
                    const int R0=(r+x)%k;
                    if (i>0) dp[i&1][j][r]=dp[(i-1)&1][j][R0];
                    if (j>0) dp[i&1][j][r]+=dp[i&1][j-1][R0];
                    dp[i&1][j][r]%=mod;
                }
            }
        }
        return dp[(m-1)&1][n-1][0];
    }
};