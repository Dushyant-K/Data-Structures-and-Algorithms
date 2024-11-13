class Solution {
    private:
    int solve(int idx1, int idx2, string s, string t, vector<vector<int>>& dp){
        if(idx1==0||idx2==0)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if(s[idx1-1]==t[idx2-1]){
            return dp[idx1][idx2]=1+solve(idx1-1,idx2-1,s,t,dp);
        }
        else{
            int l = solve(idx1,idx2-1,s,t,dp);
            int r = solve(idx1-1,idx2,s,t,dp);
            return dp[idx1][idx2]=max(l,r);
        }
    }
    int longestPalindromeSubseq(string s) {
        //Approach-1(Memoization Method-top Down Dynamic Programming)
        // int length = s.length();
        // string t=s;
        // reverse(s.begin(),s.end());
        // vector<vector<int>> dp(length+1,vector<int>(length+1,-1));
        // return solve(length,length,s,t,dp);

        //Approach-2(TabulationMethod-Bottom up dynamic programming)
        int length=s.length();
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(length+1,vector<int>(length+1,0));
        
        for(int i=1;i<=length;i++){
            for(int j=1;j<=length;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    int l = dp[i-1][j];
                    int r = dp[i][j-1];
                    dp[i][j]=max(l,r);
                }
            }
        }
        return dp[length][length];
    }
public:
    int minInsertions(string s) {
        int length=s.length();
        int lengthOfPal=longestPalindromeSubseq(s);
        return (length-lengthOfPal);
    }
};