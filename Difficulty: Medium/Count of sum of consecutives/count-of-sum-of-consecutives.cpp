//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getCount(int N) {
        int count=0;
        for (int k = 2; k * (k - 1) / 2 < N; ++k) {
        // Check if (N - k*(k-1)/2) is divisible by k
        int numerator = N - (k * (k - 1)) / 2;
        if (numerator % k == 0) {
            count++;
        }
    }
    
    return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.getCount(N) << endl;
    }
    return 0;
}
// } Driver Code Ends