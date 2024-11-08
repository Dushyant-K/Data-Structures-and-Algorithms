//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int solve(int idx, vector<int>& height, vector<int>& dp){
        if(idx==0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        
        int left = solve(idx-1,height,dp)+abs(height[idx]-height[idx-1]);
        int right = INT_MAX;
        if(idx>1)right = solve(idx-2,height,dp) + abs(height[idx]-height[idx-2]);
        return dp[idx] = min(left,right);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Approach-1(Memoization Method - Top Down Dynamic Programming)
        // vector<int> dp(n,-1);
        // return solve(n-1,height,dp);
        
        //Approach-2(Tabulation Method)
        vector<int> dp(n,-1);
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]);
        for(int i=2;i<=n-1;i++){
            int left = abs(height[i]-height[i-1])+dp[i-1];
            int right = abs(height[i]-height[i-2])+dp[i-2];
            dp[i] = min(left,right);
        }
        return dp[n-1];
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
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends