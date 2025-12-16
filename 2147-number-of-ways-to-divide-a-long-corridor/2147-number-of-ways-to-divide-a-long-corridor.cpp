class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int curr, int count, vector<bool>& corridor, int& n,
              vector<vector<int>>& dp) {
        if (curr == n - 1)
            return dp[curr][count + corridor[curr]] =
                       count + corridor[curr] == 2;

        if (dp[curr][count + corridor[curr]] != -1)
            return dp[curr][count + corridor[curr]];
        int total = 0;
        if (count + corridor[curr] == 2) {
            total = (total + solve(curr + 1, 0, corridor, n, dp) +
                     solve(curr + 1, 2, corridor, n, dp)) %
                    mod;
        } else {
            if (count > 2)
                return dp[curr][count + corridor[curr]] = 0;
            total = (total +
                     solve(curr + 1, count + corridor[curr], corridor, n, dp)) %
                    mod;
        }

        return dp[curr][count + corridor[curr]] = total;
    }
    int numberOfWays(string corridor) {
        // Approach-1(Using backtracking)
        //  int n = corridor.length();
        //  vector<bool> arrangement(n,0);

        // for(int i=0;i<n;i++){
        //     if(corridor[i]=='S')arrangement[i] = true;
        // }

        // return solve(0,0,arrangement,n);

        // Approach-2(Using Top Down Dynamic Programming)
        //  int n = corridor.length();
        //  vector<bool> arrangement(n,0);
        //  vector<vector<int>> dp(n,vector<int>(n+1,-1));

        // for(int i=0;i<n;i++){
        //     if(corridor[i]=='S')arrangement[i] = true;
        // }

        // return solve(0,0,arrangement,n,dp);

        // Approach-3(Using Tabulation(Bottom Up Dynamic Programming))
        int n = corridor.length();
        if (n < 2)
            return 0;
            else if(n==2){
                if(corridor=="SS")return 1;
                else return 0;
            }
        vector<int> arrangement(n, 0);
        vector<vector<int>> dp(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S')
                arrangement[i] = 1;
        }

        if (corridor[n - 1] == 'S')
            dp[n - 1][1] = 1;
        else
            dp[n - 1][2] = 1;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= 2; j++) {
                int total = 0;
                int nj = j + arrangement[i];

                if (nj == 2) {
                    total = (dp[i + 1][0] + dp[i + 1][2]) % mod;
                } else if (nj < 3) {
                    total = dp[i + 1][nj];
                }

                dp[i][j] = total;
            }
        }

        return dp[0][0];
    }
};