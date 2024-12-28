//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution {
    private:
     int lastOneStanding(int n, int k) {
            if (n == 1) 
                return 0; // Base case: 0-indexed safe position
            return (lastOneStanding(n - 1, k) + k) % n;
        }
  public:
    int josephus(int n, int k) {
        // Approach-1
        
         // Calculate the safe position using 0-based indexing
        int safeIndex = lastOneStanding(n, k);

        // Return the position as 1-based index
        return safeIndex + 1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t; // testcases
    while (t--) {
        int n, k;
        cin >> n >> k; // taking input n and k

        // calling josephus() function
        Solution ob;
        cout << ob.josephus(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends