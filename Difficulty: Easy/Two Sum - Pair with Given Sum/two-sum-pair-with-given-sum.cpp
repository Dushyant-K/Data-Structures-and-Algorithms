//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
    // code here
  unordered_map<int, int> seen; // Map to store elements and their indices

    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i]; // The value needed to reach the target

        // Check if the complement exists in the map
        if (seen.find(complement) != seen.end()) {
            // Found a pair (arr[i], complement) at distinct indices
            return true;
        }

        // Store the current element with its index
        seen[arr[i]] = i;
    }

    // No pair found
    return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends