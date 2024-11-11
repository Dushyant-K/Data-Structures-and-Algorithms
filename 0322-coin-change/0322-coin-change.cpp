class Solution {
    private:
    int solve(int idx, int amount, vector<int> coins, vector<vector<int>>& dp){
        if(idx==0){
            if(amount%coins[0]==0)return (amount/coins[0]);
            else return 1e9;
        }

        if(dp[idx][amount]!=-1)return dp[idx][amount];
        //Take/notTake Method
        int notTake = 0+solve(idx-1,amount,coins,dp);
        int take = INT_MAX;
        if(coins[idx]<=amount){
            take = 1+solve(idx,amount-coins[idx],coins,dp);
        }
        return dp[idx][amount]=min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        //Couldn't solve it using Greedy algorithm
        // sort(coins.begin(),coins.end());
        // int n = coins.size();
        // int left=n-1;
        // int count=0;
        // while(left>=0&&amount>0){
        //     while(amount>=coins[left]){
        //         amount-=coins[left];
        //         count++;
        //     }
        //     left--;
        // }
        // return (amount>0)?-1:count;

        //Approach-1(Memoization Top Down dynamic programming)
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};