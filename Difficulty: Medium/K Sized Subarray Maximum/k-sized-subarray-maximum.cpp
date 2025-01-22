//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // Approach-1(Sliding window)
    vector<int> result;
    deque<int> dq; // Stores indices of potential max elements

    for (int i = 0; i < arr.size(); i++) {
        // Remove indices that are out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove elements smaller than the current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Add current element index to the deque
        dq.push_back(i);

        // Add the maximum for the current window to the result
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends