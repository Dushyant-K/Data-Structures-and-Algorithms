//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int distinctSubsequences(int idx, string temp, string str, int n, set<string>& st){
        if(idx==n){
            if(temp!=""&&st.find(temp)==st.end()){
                st.insert(temp);
                return 1;
            }
            else{
                return 0;
            }
        }
        
        int l = distinctSubsequences(idx+1,temp+str[idx],str,n,st);
        
        int r = distinctSubsequences(idx+1,temp,str,n,st);
        
        return l+r;
    }
    int countDistinctSubsequences(string str) {
        int n = str.length();
        vector<int> dp(n + 1, 0); // DP array to store the number of distinct subsequences up to each index
        dp[0] = 1; // Base case: empty string has one subsequence (itself)

        unordered_map<char, int> lastOccur; // To track the last occurrence of characters

        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % 1000000007; // Each subsequence can be with or without the current character

            char ch = str[i - 1];
            if (lastOccur.find(ch) != lastOccur.end()) {
                // Remove duplicates if the character has appeared before
                dp[i] = (dp[i] - dp[lastOccur[ch] - 1] + 1000000007) % 1000000007;
            }

            lastOccur[ch] = i; // Update the last occurrence of the current character
        }
        
        return dp[n] - 1; // Subtract the empty subsequence
    }
    string betterString(string str1, string str2) {
        // Approach-1(Recursion)
        // set<string> st;
        // int count1 = distinctSubsequences(0,"",str1,str1.length(),st);
        // st.clear();
        // int count2 = distinctSubsequences(0,"",str2,str2.length(),st);
        
        // if(count1>=count2)return str1;
        // return str2;
        
        //Aprroach-2(Memoization Method)
        int count1 = countDistinctSubsequences(str1);
        int count2 = countDistinctSubsequences(str2);

        return count1 >= count2 ? str1 : str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends