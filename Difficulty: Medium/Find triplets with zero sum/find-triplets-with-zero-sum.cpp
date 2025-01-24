//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find triplets with zero sum.
    bool findTriplets(vector<int> &arr) {
        // Approach-1(Two pointer)
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            int low=i+1;
            int high=n-1;
            while(low<high){
                int sum=arr[low]+arr[i]+arr[high];
                if(sum==0)return true;
                else if(sum>0)high--;
                else low++;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        if (obj.findTriplets(arr))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}

// } Driver Code Ends