//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Approach-1
         int n=arr.size();
        int low=0;
        int high=n-1;
        int ans = INT_MAX;
        int idx=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[low]<=arr[high]){//Small Optimization(Occurs when we have crossed the point of rotation or is on the other side of it.)
                if(ans>arr[low]){
                    ans = arr[low];
                    idx = low;
                }
                break;
            }
            if(arr[low]<=arr[mid]){
                if(ans>arr[low]){
                    ans = arr[low];
                    idx = low;
                }
                low=mid+1;
            }
            else{
               if(ans>arr[mid]){
                    ans = arr[mid];
                    idx = mid;
                }
                high = mid-1;
            }
        }
        return idx;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends