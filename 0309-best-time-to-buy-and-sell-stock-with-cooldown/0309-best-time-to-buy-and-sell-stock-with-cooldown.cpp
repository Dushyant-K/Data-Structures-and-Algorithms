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
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};