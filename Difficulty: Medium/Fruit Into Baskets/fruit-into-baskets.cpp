//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        //Approach-1
        // int n = arr.size();
        // int maxLength=0;
        // for(int i=0;i<n;i++){
        //     set<int> st;
        //     for(int j=i;i<n;j++){
        //         st.insert(arr[j]);
        //         if(st.size()<=2){
        //             maxLength = max(maxLength,(j-i+1));
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return maxLength;
        
        //Approach-2
        int left =0;
        int right =0;
        int maxLength =0;
        map<int,int> mpp;
        while(right<arr.size()){
            mpp[arr[right]]++;
            if(mpp.size()>2){
                mpp[arr[left]]--;
                if(mpp[arr[left]]==0)mpp.erase(arr[left]);
                left++;
            }
            int length = (right-left+1);
            maxLength = max(length,maxLength);
            right++;
        }
        return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends