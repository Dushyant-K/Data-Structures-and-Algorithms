//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = (1e9+7);
    private:
    int solve(int idx, int arr[], int sum,vector<vector<int>>& dp){
        // if(sum==0)return 1;//Edge Case(Think for zeros(it doesn't consider them))
        if(idx==0){
            if(sum==0&&arr[idx]==0)return 2;
            if(sum==0||arr[idx]==sum)return 1;
            return 0;
        }
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        
        int notPick = solve(idx-1,arr,sum,dp);
        int pick=0;
        if(arr[idx]<=sum){
            pick = solve(idx-1,arr,sum-arr[idx],dp);
        }
        return dp[idx][sum]=(pick+notPick)%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Approach-1(Memoization Method-Top Down Dynamic programming)
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
        
        //Approach-2(Tabulation Method-Bottom up dynamic programming)
//         vector<vector<int>> dp(n,vector<int>(sum+1,0));
//         for(int i=0;i<n;i++)dp[i][0]=1;
//         if(arr[0]<=sum)dp[0][arr[0]]=1;
//         for(int i=1;i<n;i++){
//             for(int j=0;j<=sum;j++){
//                 int notPick = dp[i-1][j];
//                 int pick = 0;
//                 if(arr[0]<=j){
//                     pick = dp[i-1][j-arr[0]];
//                 }
//                 dp[i][j]=pick+notPick;
//             }
//         }
//         return dp[n-1][sum];
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends