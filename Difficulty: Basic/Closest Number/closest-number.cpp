//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int closestNumber(int N , int M) {
        int quotient = N / M;
    
    int n1 = M * quotient;
    int n2 = (N * M > 0) ? (M * (quotient + 1)) : (M * (quotient - 1));
    
   
    if (abs(N - n1) == abs(N - n2)) {
        return (abs(n1) > abs(n2)) ? n1 : n2;
    }
    
    return (abs(N - n1) < abs(N - n2)) ? n1 : n2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends