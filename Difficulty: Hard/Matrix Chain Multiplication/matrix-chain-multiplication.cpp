//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    int solve(int i, int j , vector<int> arr, vector<vector<int>>& dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        //trying out all partitions on that index
        int mini=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int steps = arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // Approach-1(Memoization Method-Top down dynamic programming)
        // int n=arr.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solve(1,n-1,arr,dp);
        
        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=1;i<n;i++)dp[i][i]=0;
        
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int mini=1e9;
                for(int k=i;k<=j-1;k++){
                    int steps = arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    mini=min(mini,steps);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(arr) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends