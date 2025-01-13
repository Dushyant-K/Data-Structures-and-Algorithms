class Solution {
public:
    int solve(vector<int>& arr, int k, int i, vector<int>& dp) {
        //base case of the soslve function index out of bound
        if (i >= arr.size()) {
            return 0;
        }
// if solution already save in dp than direct use it 
        if (dp[i] != -1) {
            return dp[i];
        }

        int ans = 0, maxElem = INT_MIN, currentSum = 0;

        
        for (int j = i; j < min((int)arr.size(), i + k); j++) {
            //max element from current subarray 
            maxElem = max(maxElem, arr[j]); 
            //length of current subarray and multiply with maximum value of that subarray
            currentSum = (j - i + 1) * maxElem; 
            //recursive call for the next part of array and compare the maximum with answer 
            ans = max(ans, currentSum + solve(arr, k, j + 1, dp)); 
        }
  //save answer into index i in the dp vector for future use and return it 
        return dp[i] = ans; 
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        //dp intialization of size of array
        vector<int> dp(arr.size(), -1); 
        //solve funcion call for the answer from index starting at 0
        return solve(arr, k, 0, dp);
    }
};
