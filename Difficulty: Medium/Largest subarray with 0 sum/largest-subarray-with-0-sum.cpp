//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Approach-1
        int prefixSum=0;
        map<int,int> preSumMap;
        int length = 0;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            if(prefixSum==0){
                length = max(length,i+1);
            }
            else{
                if(preSumMap.find(prefixSum)!=preSumMap.end()){
                length = max(length,i-preSumMap[prefixSum]);
            }
            else{
                preSumMap[prefixSum]=i;
                }
            }
        }
        return length;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends