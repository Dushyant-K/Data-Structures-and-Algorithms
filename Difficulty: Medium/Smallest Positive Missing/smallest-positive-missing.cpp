//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        //Approach-1(hashing by array)
        int n=arr.size();
        vector<int> hash(1e6+1,0);
        for(int i=0;i<n;i++){
            if(arr[i]>0)hash[arr[i]]++;
        }
        
        for(int i=1;i<1e6+1;i++){
            if(hash[i]==0)return i;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends