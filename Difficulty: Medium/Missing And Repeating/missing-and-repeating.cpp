//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // bucket Method
        int xor1=0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            xor1=xor1^arr[i];
            xor1 = xor1^(i+1);
        }
        int bitNo=0;
        while(1){
            if((xor1&(1<<bitNo))!=0){
                break;
            }
            bitNo++;
        }
        int zero=0;
        int one=0;
        for(int i=0;i<n;i++){
            if(arr[i]&(1<<bitNo)){
                one= one^arr[i];
            }
            else{
                zero=zero^arr[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(i&(1<<bitNo)){
                one = one^i;
            }
            else{
                zero = zero^i;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(one==arr[i])count++;
        }
        if(count==2)return {one,zero};
        return {zero,one};
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
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends