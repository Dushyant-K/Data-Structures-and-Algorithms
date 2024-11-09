//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int solve(int idx, int m, vector<vector<int>> arr, int last, vector<vector<int>>& dp){
        //Base-Case
        if(idx==0){
            int maxi = 0;
            for(int i=0;i<m;i++){
                if(i!=last){
                    maxi = max(maxi,arr[0][i]);
                }
            }
            return maxi;
        }
        if(dp[idx][last]!=-1)return dp[idx][last];
        
        //Now we will do the rest
        int maxi = 0;
        for(int i=0;i<m;i++){
            if(i!=last){
                int points = arr[idx][i]+solve(idx-1,m,arr,i,dp);
                maxi = max(maxi,points);
            }
        }
        return dp[idx][last]=maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Approach-1(Memoziation Method- Top Down Dynamic Programming)
        // int m = arr[0].size();
        // vector<vector<int>> dp(n,vector<int>(m+1,0));
        // return solve(n-1,m,arr,m,dp);
        
        //Tabulation Method
        vector<vector<int>> dp(n,vector<int>(4,0));
        dp[0][0] = max(arr[0][1],arr[0][2]);
        dp[0][1] = max(arr[0][0],arr[0][2]);
        dp[0][2] = max(arr[0][0],arr[0][1]);
        dp[0][3] = max(arr[0][0],max(arr[0][1],arr[0][2]));
        
        for(int i=1;i<n;i++){
            for(int last=0;last<=3;last++){
                int maxi = 0;
               for(int task = 0;task<=2;task++){
                   if(task!=last){
                   int points = arr[i][task]+dp[i-1][task];
                   maxi = max(maxi,points);
                   }
                   dp[i][last]=maxi;
               }
            }
        }
        return dp[n-1][3];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends