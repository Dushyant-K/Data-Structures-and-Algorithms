class Solution {
    private:
    int solve(int idx1, int idx2, string s, string t, vector<vector<int>>& dp){
        if(idx2<0) return 1;//It means i got the string taht i was searching for in s
        if(idx1<0) return 0; //It means that there is no more matching available in s and t is still non empty
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        int l=0,r=0;
        if(s[idx1]==t[idx2]){
             l = solve(idx1-1,idx2-1,s,t,dp)+solve(idx1-1,idx2,s,t,dp);
        }
        else{
             r = solve(idx1-1,idx2,s,t,dp);
        }
        return dp[idx1][idx2]=l+r;
    }
public:
    int numDistinct(string s, string t) {
        //Approach-1(Memoization Method-Top Down dynamic programming)
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,s,t,dp);
    }
};