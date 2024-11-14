class Solution {
    private:
    int solve(int idx1, int idx2, string s, string t, vector<vector<int>>& dp){
        if(idx2<0) return 1;//It means i got the string taht i was searching for in s
        if(idx1<0) return 0; //It means that there is no more matching available in s and t is still non empty
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if(s[idx1]==t[idx2]){
             return dp[idx1][idx2]=solve(idx1-1,idx2-1,s,t,dp)+solve(idx1-1,idx2,s,t,dp);
        }
        else{
             return dp[idx1][idx2] = solve(idx1-1,idx2,s,t,dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        //Approach-1(Memoization Method-Top Down dynamic programming)
        // int n1=s.length();
        // int n2=t.length();
        // vector<vector<int>> dp(n1,vector<int>(n2,-1));
        // return solve(n1-1,n2-1,s,t,dp);

        //Tabulation method-(Bottom up dynamic programming)
        int n1=s.length();
        int n2=t.length();
        vector<vector<long long>> dp(n1+1,vector<long long>(n2+1,0));
        for(int i=0;i<=n1;i++)dp[i][0]=1;
        for(int i=1;i<=n2;i++)dp[0][i]=0;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[n1][n2];
    }
};