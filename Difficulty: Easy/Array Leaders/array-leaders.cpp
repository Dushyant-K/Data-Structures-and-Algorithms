//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> ans;
        int max=arr[n-1];
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=max){
                ans.push_back(arr[i]);
                max=arr[i];
            }
        }
        int n1 = ans.size();
        for(int i=0;i<n1/2;i++){
            int temp=ans[i];
            ans[i]=ans[n1-1-i];
            ans[n1-1-i]=temp;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t; // testcases
    while (t--) {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends