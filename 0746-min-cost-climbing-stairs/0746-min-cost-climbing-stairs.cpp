class Solution {
public:
    int solve(int idx, vector<int>& cost, vector<int>& dp){
        if(idx==0||idx==1)return cost[idx];
        if(dp[idx]!=-1)return dp[idx];

        int step1=cost[idx]+solve(idx-1,cost,dp);
        int step2=cost[idx]+solve(idx-2,cost,dp);

        return dp[idx]=min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //Approach-1(Top-Down dynamic programming)
        // int n=cost.size();
        // cost.resize(n+1);
        // cost[n]=0;
        // vector<int> dp(n+1,-1);
        // return solve(n,cost,dp);

        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        int n=cost.size();
        cost.resize(n+1);
        cost[n]=0;
        vector<int> dp(n+1,0);

        //Base-Cases
        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i=2;i<=n;i++){
            int step1=cost[i]+dp[i-1];
            int step2=cost[i]+dp[i-2];

            dp[i]=min(step1,step2);
        }

        return dp[n];
    }
};