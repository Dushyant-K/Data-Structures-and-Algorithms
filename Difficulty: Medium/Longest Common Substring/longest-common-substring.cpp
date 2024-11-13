//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        // Approach-1(Tabulation Method-Bottom Up dynamic programming)
        int n1=s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        //Main Approach
        int maxi=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxi = max(maxi,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends