//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // Approach-1(Prefix Sum)
        int n=arr.size();
        unordered_map<int,int> mpp;
        
        int prefixSum=0;
        int longest=0;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            
            if(mpp.find(prefixSum)!=mpp.end()){
                longest=max(longest,i-mpp[prefixSum]);
            }else{
                mpp[prefixSum]=i;
            }
        }
        return longest;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends