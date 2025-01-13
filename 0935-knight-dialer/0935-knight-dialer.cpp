class Solution {
public:
    int mod=1e9+7;
    int solve(int number, int idx, vector<vector<int>>& moves, vector<vector<int>>& dp){
        if(number==0)return 1;
        if(dp[number][idx]!=-1)return dp[number][idx];

        int ways=0;
        for(auto it:moves[idx]){
            ways=(ways+solve(number-1,it,moves,dp)%mod)%mod;
        }
        return dp[number][idx]=ways;
    }
    int knightDialer(int n) {
        //Approach-1
        vector<vector<int>> moves={
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {0,3,9},
            {},
            {0,1,7},
            {2,6},
            {1,3},
            {2,4}
            };

            int ways=0;
            vector<vector<int>> dp(n,vector<int>(10,-1));
            for(int i=0;i<=9;i++){
                ways=(ways+solve(n-1,i,moves,dp)%mod)%mod;
            }
        return ways;
    }
};