//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    void sumOfSubsets(int idx, int sum, vector<int>& ans, vector<int> arr, int n){
        if(idx==n){
            ans.push_back(sum);
            return;
        }
        
        //Picking the element
        sumOfSubsets(idx+1,sum+arr[idx],ans,arr,n);
        //Not picking up the element
        sumOfSubsets(idx+1,sum,ans,arr,n);
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        //Approach-1
        vector<int> ans;
        sumOfSubsets(0,0,ans,arr,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends