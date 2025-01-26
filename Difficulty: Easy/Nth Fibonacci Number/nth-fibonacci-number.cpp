//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    int solve(int n){
        if(n==0||n==1)return n;
        
        return (solve(n-1)+solve(n-2));
    }
  public:
    int nthFibonacci(int n) {
        // Appproach-1(Recursion)
        return solve(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends