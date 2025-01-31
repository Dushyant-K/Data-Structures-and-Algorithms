//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
   void backtrack(string &s, int index, set<string> &uniquePermutations) {
    if (index == s.size()) {
        uniquePermutations.insert(s);
        return;
    }
    
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        backtrack(s, index + 1, uniquePermutations);
        swap(s[index], s[i]);  // backtrack
    }
}
  public:
    vector<string> findPermutation(string &s) {
        // Approach-1(Recursion backtracking-leap of faith)
        set<string> uniquePermutations;
    backtrack(s, 0, uniquePermutations);
    return vector<string>(uniquePermutations.begin(), uniquePermutations.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends