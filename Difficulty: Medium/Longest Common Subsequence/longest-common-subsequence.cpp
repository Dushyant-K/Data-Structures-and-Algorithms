//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
    private:
    int solve(int idx1, int idx2, string& s1, string& s2, int n1, int n2, vector<vector<int>>& dp){
        if(idx1==n1||idx2==n2)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        
        if(s1[idx1]==s2[idx2]){
             return 1+solve(idx1+1,idx2+1,s1,s2,n1,n2,dp);
        }
        
        return dp[idx1][idx2]=max(0+solve(idx1+1,idx2,s1,s2,n1,n2,dp),0+solve(idx1,idx2+1,s1,s2,n1,n2,dp));
    }
  public:
    // Function to find the length of the longest common subsequence in two strings.
    int lcs(string& s1, string& s2) {
        // Approach-1
        int n1=s1.length();
        int n2=s2.length();
        
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(0,0,s1,s2,n1,n2,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends