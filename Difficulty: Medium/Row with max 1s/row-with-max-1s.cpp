//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  
    int lowerBound(vector<int> arr, int target){
        int low =0;
        int high = arr.size()-1;
        int ans = arr.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=target){
                ans=mid;
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int> > &arr) {
       int n =arr.size();
       int m = arr[0].size();
       int cnt_max = 0;
       int ind_max=-1;
       for(int i=0;i<n;i++){
           int cnt_ones = m - (lowerBound(arr[i],1));
           if(cnt_ones>cnt_max){
               cnt_max  = cnt_ones;
               ind_max = i;
           }
       }
       return ind_max;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends