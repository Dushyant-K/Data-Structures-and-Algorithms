class Solution {
    private:
    int solve(int idx1, int idx2, string text1,string text2, vector<vector<int>>& dp){
        if(idx1==0||idx2==0)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        //Match/noMatch
        if(text1[idx1-1]==text2[idx2-1]) return dp[idx1][idx2]=1+solve(idx1-1,idx2-1,text1,text2,dp);

        return dp[idx1][idx2]=max(solve(idx1,idx2-1,text1,text2,dp),solve(idx1-1,idx2,text1,text2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        //Approach-1(Memoization Method-Top Down Dynamic Programming)
        // int idx1=text1.length();
        // int idx2 = text2.length();
        // vector<vector<int>> dp(idx1+1,vector<int>(idx2+1,-1));
        // return solve(idx1,idx2,text1,text2,dp);

        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        int n1=text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++)dp[i][0]=0;
        for(int i=0;i<=n2;i++)dp[0][i]=0;

        //Main Approach
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n1][n2];   
    }
};