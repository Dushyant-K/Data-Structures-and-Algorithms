class Solution {
    private:
    int solve(int idx, int buy, vector<int> prices, vector<vector<int>>& dp){
        if(idx>=prices.size())return 0;
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        if(buy){
            return dp[idx][buy]=max(-prices[idx]+solve(idx+1,0,prices,dp),0+solve(idx+1,1,prices,dp));
        }
        else{
            return dp[idx][buy]=max(prices[idx]+solve(idx+2,1,prices,dp),0+solve(idx+1,0,prices,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        //Approach-1(Memoization Method-Top Down dynamic programming)
        // int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return solve(0,1,prices,dp);

        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        //We don't have to write the base case as already initialized to zero
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    dp[i][j]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                }
                else{
                    if(i!=n-1)
                    dp[i][j]=max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
                    else
                    dp[i][j]=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};