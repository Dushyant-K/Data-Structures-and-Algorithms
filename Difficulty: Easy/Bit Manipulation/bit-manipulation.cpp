//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getBit(int num, int i){
        return (num & (1<<i));
    }
    void setBit(int num, int i){
        (num | (1<<i));
    }
    void clearBit(int num, int i){
        int helper = ~(1<<i);
         (num & helper);
    }
    void bitManipulation(int num, int i) {
        // Approach-1
       int get = (num & (1<<(i-1)));
       if(get!=0){
           cout<<"1 ";
       }
       else cout<<"0 ";
       
       int set = (num | (1<<(i-1)));
       cout<<set<<" ";
       
       int clear = (num & ~(1<<(i-1)));
       cout<<clear;
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