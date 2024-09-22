//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // Approach-1
        vector<long long> result;
        
        // Calculate GCD using Euclidean algorithm
        long long gcd = __gcd(A, B);
        
        // Calculate LCM using the relation: LCM(A, B) = (A * B) / GCD(A, B)
        long long lcm = (A * B) / gcd;
        
        // Store the LCM and GCD in the result vector
        result.push_back(lcm);
        result.push_back(gcd);
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends