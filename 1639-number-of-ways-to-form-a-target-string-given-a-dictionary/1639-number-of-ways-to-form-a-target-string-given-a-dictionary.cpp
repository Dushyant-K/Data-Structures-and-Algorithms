class Solution {
    private:
    int mod=1e9+7;
    int solve(int idx1, int idx2, vector<string>& words, string& target, int n, vector<vector<int>>& dp){
        if(idx1==n)return 1;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        int count=0;
        for(int i=0;i<words.size();i++){
            for(int j=idx2;j<words[i].size();j++){
                if(target[idx1]==words[i][j]){
                    count=(count+solve(idx1+1,j+1,words,target,n,dp))%mod;
                }
            }
        }
        return dp[idx1][idx2]=count;
    }
public:
    int numWays(vector<string>& words, string target) {
        //Approach-1(dp-Memoization Method)
        int n=target.size();
        int m=words[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,words,target,n,dp); 
    }
};