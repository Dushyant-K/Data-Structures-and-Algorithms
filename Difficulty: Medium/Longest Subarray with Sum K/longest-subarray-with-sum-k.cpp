//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // Approach-1(Prefix Sum-Approach)
        int n=arr.size();
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        
        int prefixSum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            if(prefixSum==k)maxi=i+1;
            
            int remaining=prefixSum-k;
            if(mpp.find(remaining)!=mpp.end()){
                maxi=max(maxi,i-mpp[remaining]);
            }
            
            if(mpp.find(prefixSum)==mpp.end())mpp[prefixSum]=i;
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends