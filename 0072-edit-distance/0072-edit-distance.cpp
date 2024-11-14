class Solution {
    private:
    int solve(int idx1, int idx2, string& s, string& t, vector<vector<int>>& dp){
        if(idx1<0){
            return idx2+1;
        }
        if(idx2<0){
            return idx1+1;
        }
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

        if(s[idx1]==t[idx2]){
            return dp[idx1][idx2]=0+solve(idx1-1,idx2-1,s,t,dp);
        }
        else{
            return dp[idx1][idx2]=1+min(solve(idx1,idx2-1,s,t,dp),min(solve(idx1-1,idx2,s,t,dp),solve(idx1-1,idx2-1,s,t,dp)));
        }
    }
public:
    int minDistance(string word1, string word2) {
        //Approach-1(Top Down dynamic programming)
        int n1=word1.length();
        int n2=word2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,word1,word2,dp);
    }
};