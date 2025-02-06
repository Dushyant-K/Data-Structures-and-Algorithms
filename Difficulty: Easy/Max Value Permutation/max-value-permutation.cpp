//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    const int MOD = 1e9 + 7;
  public:
    int maxValue(vector<int> &arr) {
    sort(arr.begin(), arr.end());  // Step 1: Sort the array

    long long sum = 0;  // Use long long to handle large values
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        sum = (sum + (1LL * arr[i] * i) % MOD) % MOD;  // Step 2: Compute sum
    }

    return sum;
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
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.maxValue(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends