//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {

        // your code here
          int el = arr[0];  // Candidate element for majority
        int count = 1;    // Count of occurrences

        // Finding a candidate element
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == el) {
                count++;  // Same element, increase count
            } else {
                count--;  // Different element, decrease count
                if (count == 0) {
                    el = arr[i];  // Change candidate
                    count = 1;
                }
            }
        }

        // Verifying if the candidate is actually a majority element
        count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == el) {
                count++;
            }
        }

        // If count of the candidate element is greater than half the size, it's the majority element
        if (count > (arr.size() / 2)) {
            return el;
        }

        // No majority element found
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends