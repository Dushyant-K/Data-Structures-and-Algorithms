//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    private:
    int solve(int idx, int arr[], vector<int>& dp){
        if(idx==0)return arr[0];
        if(idx<0)return 0;
        
        if(dp[idx]!=-1)return dp[idx];
        
        //Take and Not take method
        int take = arr[idx]+solve(idx-2,arr,dp);
        
        int notTake = 0+solve(idx-1,arr,dp);
        
        return dp[idx]=max(take,notTake);
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // Approach-1(Memoization Method-top Down Dynamic Programming)
	    vector<int> dp(n,-1);
	    return solve(n-1,arr,dp);
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends