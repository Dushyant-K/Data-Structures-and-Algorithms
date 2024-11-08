//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int solve(int idx, vector<int> arr, int k, vector<int>& dp){
        if(idx==0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int mini = INT_MAX;
        for(int i=1;i<=k;i++){
            if(idx-i>=0){
                int cost = solve(idx-i,arr,k,dp)+abs(arr[idx-i]-arr[idx]);
                mini = min(mini,cost);
            }
            else{
                break;
            }
        }
        return dp[idx]=mini;
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Approach-1(Memoization Method)
        // int n = arr.size();
        // vector<int> dp(n,-1);
        // return solve(n-1,arr,k,dp);
        
        //Approach-2
        int n = arr.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int mini = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    int cost = dp[i-j]+abs(arr[i]-arr[i-j]);
                    mini = min(mini,cost);
                }
                else break;
            }
            dp[i]=mini;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends