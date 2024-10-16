//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    //Approach-1
    int left=0;
    int right=0;
    int n  =s.length();
    int maxLength=-1;
    map<char,int> mpp;
    while(right<n){
        mpp[s[right]]++;
        while(mpp.size()>k){
            mpp[s[left]]--;
            if(mpp[s[left]]==0)mpp.erase(s[left]);
            left++;
        }
        if(mpp.size()==k){
            maxLength = max(maxLength,right-left+1);
        }
        right++;
    }
    return maxLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends