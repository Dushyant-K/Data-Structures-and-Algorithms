//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // Approach-1
        vector<int> steps(1e5,1e9);
        queue<pair<int,int>> q;
        q.push({0,start});
        steps[start]=0;
        int mod = (int)(1e5);
        while(!q.empty()){
            int step = q.front().first;
            int val = q.front().second;
            q.pop();
            if(val==end)return step;
            for(int i=0;i<arr.size();i++){
                int num = (val*arr[i])%mod;
                if(step+1<steps[num]){
                    steps[num]=step+1;
                    q.push({step+1,num});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends