class Solution {
    private:
    bool solve(int idx1, int idx2, string s, string p, vector<vector<int>>& dp){
        if(idx1<0&&idx2<0)return true;
        if(idx2<0)return false;
        if(idx1<0){
            for(int i=0;i<=idx2;i++){
                if(p[i]!='*')return false;
            }
            return true;
        }
        if(dp[idx1][idx2]!=0)return dp[idx1][idx2];
        if(s[idx1]==p[idx2]||p[idx2]=='?'){
            return dp[idx1][idx2]=solve(idx1-1,idx2-1,s,p,dp);
        }
        else{
            if(p[idx2]!='*')return false;
            return dp[idx1][idx2]=solve(idx1,idx2-1,s,p,dp)||solve(idx1-1,idx2,s,p,dp);
        }
    }
public:
    bool isMatch(string s, string p) {
        //Approach-1(Memoization Method-Top Down dynamic programming)
        // int n1=s.length();
        // int n2=p.length();
        // vector<vector<int>> dp(n1,vector<int>(n2,0));
        // return solve(n1-1,n2-1,s,p,dp);

        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        int n1=s.length();
        int n2=p.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n1;i++)dp[i][0]=0;
        for(int i=1;i<=n2;i++){
            if(p[i-1]=='*')dp[0][i]=dp[0][i-1];
            else break;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    if(p[j-1]=='*')dp[i][j]=dp[i][j-1]||dp[i-1][j];
                    else dp[i][j]=0;
                }
            }
        }
        return dp[n1][n2];
    }
};