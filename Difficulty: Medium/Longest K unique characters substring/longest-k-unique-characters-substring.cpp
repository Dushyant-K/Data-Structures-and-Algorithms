//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int left = 0;
        int right = 0;
        int maxLength = -1; // Use -1 as default, if no such substring exists
        map<char, int> mpp;

        while (right < s.length()) {
            // Add current character to the map
            mpp[s[right]]++;
            
            // If the size of map (unique characters) exceeds k, shrink the window from the left
            while (mpp.size() > k) {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) {
                    mpp.erase(s[left]);
                }
                left++;
            }

            // If the number of unique characters is exactly k, update the maximum length
            if (mpp.size() == k) {
                maxLength = max(maxLength, right - left + 1);
            }

            // Move to the next character
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