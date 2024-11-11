//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int solve(int idx, int capacity, vector<int> val, vector<int> wt, vector<vector<int>>& dp){
        if(idx==0){
            if(wt[0]<=capacity)return val[0];
            return 0;
        }
        if(dp[idx][capacity]!=-1)return dp[idx][capacity];
        //pick/notPick
        int notPick = solve(idx-1,capacity,val,wt,dp);
        int pick = INT_MIN;
        if(wt[idx]<=capacity){
            pick = val[idx]+solve(idx-1,capacity-wt[idx],val,wt,dp);
        }
        return dp[idx][capacity]=max(pick,notPick);
    }
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // Approach-1(Memoization Method-Top down dynamic programming)
        // int n = val.size();
        // vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        // return solve(n-1,capacity,val,wt,dp);
        
        //Approach-2(Tabulation Method-Bottom up dynamic programming)
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,0));
        for(int i=wt[0];i<=capacity;i++){
            dp[0][i]=val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=capacity;j++){
                int notTake = 0+dp[i-1][j];
                int take = INT_MIN;
                if(wt[i]<=j){
                    take = val[i]+dp[i-1][j-wt[i]];
                }
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[n-1][capacity];
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends