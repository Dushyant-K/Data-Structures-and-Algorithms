//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        // Approach-1
        vector<int> divisor;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divisor.push_back(i);
                if(n/i!=i)divisor.push_back(n/i);
            }
        }
        sort(divisor.begin(),divisor.end());
        for(int i=0;i<divisor.size();i++){
            cout<<divisor[i]<<" ";
        }
        return;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends