//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    private:
    bool solve(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target==0)return true;//If any time i get a subsequence with sum of elements as k
        if(idx==0)return(arr[idx]==target);//bcz the sum has to be equal to be arr[0] for true
        
        //Check for that sub-problem 
        if(dp[idx][target]!=-1)return dp[idx][target];
        //Now we gonna apply the take/notTake method
        bool notTake = solve(idx-1,target,arr,dp);
        //Now if we take
        bool take = false;
        if(target>=arr[idx]){
            take = solve(idx-1,target-arr[idx],arr,dp);
        }
        return dp[idx][target]=take|notTake;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // Approach-1(Memoization method-Top Down Dynamic Programming)
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends