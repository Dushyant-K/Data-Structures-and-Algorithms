//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int hasharray[n+1]={0};
        for(int i=0;i<n;i++){
            hasharray[arr[i]]++;
        }
        vector<int> ans;
        int repeating,missing;
        for(int i=1;i<=n;i++){
            if(hasharray[i]==2)repeating = i;
            
            else if(hasharray[i]==0)missing=i;
        }
        ans.push_back(repeating);
        ans.push_back(missing);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends