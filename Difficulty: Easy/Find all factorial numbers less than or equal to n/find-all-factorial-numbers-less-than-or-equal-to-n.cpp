//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        vector<long long> factorials; // To store the factorial numbers
        long long fact = 1; // Start with 0! = 1
        int i = 1;

        while (fact <= n) {
            factorials.push_back(fact); // Add the current factorial to the list
            i++; // Move to the next number
            fact *= i; // Calculate the next factorial
        }
        
        return factorials;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends