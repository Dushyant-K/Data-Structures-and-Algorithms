class Solution {
    private:
    int solve(int idx, vector<int> coins, int amount, vector<vector<int>> dp){
        if(idx==0){
            return (amount%coins[0]==0);
        }
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        //take/notTake Method
        int notTake = solve(idx-1,coins,amount,dp);
        int take = 0;
        if(coins[idx]<=amount){
            take = solve(idx,coins,amount-coins[idx],dp);
        }
        return dp[idx][amount]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        //Approach-1(Memoization method-top Down Dynamic Programming)
        // int n = coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // return solve(n-1,coins,amount,dp);

        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        // int n= coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,0));
        // for(int i=0;i<=amount;i++){
        //     if(i%coins[0]==0)dp[0][i]=1;
        // }
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<=amount;j++){
        //         long notTake = dp[i-1][j];
        //         long take=0;
        //         if(coins[i]<=j){
        //             take = dp[i][j-coins[i]];
        //         }
        //         dp[i][j]=(take+notTake);
        //     }
        // }
        // return dp[n-1][amount];

        //Approach-3(Space optimisation)
         int n= coins.size();
         vector<int> prev(amount+1,0);
         for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)prev[i]=1;
         }
        for(int i=1;i<n;i++){
            vector<int>curr(amount+1,0);
            for(int j=0;j<=amount;j++){
                long notTake = prev[j];
                long take=0;
                if(coins[i]<=j){
                    take = curr[j-coins[i]];
                }
                curr[j]=(take+notTake);
            }
            prev = curr;
        }
        return prev[amount];
    }
};