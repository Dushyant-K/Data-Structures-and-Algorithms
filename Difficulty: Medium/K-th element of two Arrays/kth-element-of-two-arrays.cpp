//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
        int n1= arr1.size();
        int n2 = arr2.size();
        int count=1;
        int p1=0,p2=0;
        while(p1<n1 && p2<n2){
            if(arr1[p1]<arr2[p2]){
                if(count==k){
                    return arr1[p1];
                }
                count++;
                p1++;
            }
            
            else{
                if(count==k){
                    return arr2[p2];
                }
                count++;
                p2++;
            }
        }
        
        while(p1<n1){
            if(count==k){
                return arr1[p1];
            }
            count++;
            p1++;
        }
        
        while(p2<n2){
            if(count==k){
                return arr2[p2];
            }
            count++;
            p2++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> arr1(n), arr2(m);
        // 		int arr1[n],arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        Solution ob;
        cout << ob.kthElement(arr1, arr2, k) << endl;
    }
    return 0;
}
// } Driver Code Ends