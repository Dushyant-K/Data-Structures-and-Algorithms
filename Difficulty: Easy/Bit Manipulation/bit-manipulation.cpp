//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        //Get ith bit
        if(num & (1<<(i-1))){
        cout<<"1 ";
        }
        else
        cout<<"0 ";
        
        //Set ith bit
        cout<<(num | (1<<(i-1)))<<" ";
        
        //Clear ith bit
        cout<<(num & ~(1<<(i-1)));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends