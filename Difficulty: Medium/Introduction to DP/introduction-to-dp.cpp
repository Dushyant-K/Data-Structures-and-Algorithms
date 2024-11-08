//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int mod = (1e9+7);
    private:
    int solve(int n, vector<int>& dp){
        if(n<=1)return n;
        
        //check if we have already solved the subproblem or not
        if(dp[n]!=-1)return dp[n];
        
        int left = solve(n-1,dp);
        int right = solve(n-2,dp);
        
        return dp[n]=(left+right)%mod;
    }
  public:
    long long int topDown(int n) {
        // Approach-1(Memoization-Method - Top down Dynamic Programming)
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
    long long int bottomUp(int n) {
        // Tabulation Method(Bottom up Dynamic Programming)
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends