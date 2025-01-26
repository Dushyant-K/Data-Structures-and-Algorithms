//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int reverseExponentiation(int n) {
        // Approach-1
        int rev=0;
        int dummy=n;
        while(dummy!=0){
            int digit=dummy%10;
            dummy=dummy/10;
            
            rev=rev*10+digit;
        }
        
        return pow(n,rev);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T; // test cases

    while (T--) {
        int n;
        cin >> n; // input N

        Solution ob;
        // power of the number to its reverse
        int ans = ob.reverseExponentiation(n);
        cout << ans << endl;
    }

    return 0;
}

// } Driver Code Ends