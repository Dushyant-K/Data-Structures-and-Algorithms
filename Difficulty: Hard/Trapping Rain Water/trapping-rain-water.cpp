//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    int trappingWater(vector<int> &arr) {
        // code here
    int n = arr.size();
    if (n == 0) return 0;

    // Create two arrays to store the maximum height to the left and right of each block
    std::vector<int> leftMax(n), rightMax(n);

    // Compute the maximum height to the left of each block
    leftMax[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = std::max(leftMax[i - 1], arr[i]);
    }

    // Compute the maximum height to the right of each block
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i + 1], arr[i]);
    }

    // Calculate the trapped water
    int waterTrapped = 0;
    for (int i = 0; i < n; ++i) {
        // Water trapped at each block is the minimum of the left and right max heights minus the height of the block
        waterTrapped += std::min(leftMax[i], rightMax[i]) - arr[i];
    }

    return waterTrapped;
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
        int res = ob.trappingWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends