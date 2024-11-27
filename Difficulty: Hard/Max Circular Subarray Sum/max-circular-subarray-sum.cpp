//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int kadaneMax(const vector<int>& arr) {
    int max_sum = INT_MIN, current_sum = 0;
    for (int num : arr) {
        current_sum = max(num, current_sum + num);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}
int kadaneMin(const vector<int>& arr) {
    int min_sum = INT_MAX, current_sum = 0;
    for (int num : arr) {
        current_sum = min(num, current_sum + num);
        min_sum = min(min_sum, current_sum);
    }
    return min_sum;
}
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
    int total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }

    int max_kadane = kadaneMax(arr); // Maximum subarray sum (non-circular)
    int min_kadane = kadaneMin(arr); // Minimum subarray sum

    // If all elements are negative, return the result of kadaneMax
    if (total_sum == min_kadane) {
        return max_kadane;
    }

    // Maximum of non-circular and circular cases
    return max(max_kadane, total_sum - min_kadane);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends