class Solution {
public:
    int solve(int idx, string&s, int n, vector<int>& dp){
        if(idx==n)return 1;
        if(s[idx]=='0')return 0;
        if(dp[idx]!=-1)return dp[idx];

        //Don't Club it
        int left=solve(idx+1,s,n,dp);
        //Club it
        int right=0;
         if (idx < n-1 && stoi(s.substr(idx, 2)) <= 26) {
            right = solve(idx + 2, s, n,dp);
        }

        return dp[idx]=left+right;
    }
    int numDecodings(string s) {
        //Approach-1(Recursion backtracking-Memoization Method-Top down dynamic programming)
        // int n=s.length();
        // vector<int> dp(n+1,-1);
        // return solve(0,s,n,dp);

        //Approach-2(Tabulation-Bottom Up Dynamic Programming)
        int n=s.length();
        vector<int> dp(n+1);
        
        for(int i=0;i<n;i++){
            if(s[i]=='0')dp[i]=0;
        }
        dp[n]=1;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')continue;
            int left=dp[i+1];
            int right=0;
            if(i<n-1&&stoi(s.substr(i,2))<=26)right=dp[i+2];

            dp[i]=left+right;
        }

        return dp[0];
    }
};