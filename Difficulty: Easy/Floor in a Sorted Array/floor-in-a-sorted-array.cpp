//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Approach-1(Binary Search)
        int n=arr.size();
        
        int low=0;
        int high=n-1;
        bool flag=false;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]<=x){
                flag=true;
                low=mid+1;
            }
            else high=mid-1;
        }
        return flag==true? high:-1;
        
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, x);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends