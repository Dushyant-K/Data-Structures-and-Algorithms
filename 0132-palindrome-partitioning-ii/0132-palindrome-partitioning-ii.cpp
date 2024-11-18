class Solution {
    private:
    bool checkPalindrome(int i, int j, string s){
        while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;

    }
    int solve(int i, string& s, vector<int>& dp) {
        if (i == s.size()) return 0; // No cuts needed for an empty substring.

        if (dp[i] != -1) return dp[i];

        int n = s.size();
        int mini = INT_MAX;

        for (int k = i; k < n; k++) {
            if (checkPalindrome(i, k, s)) { 
                int cuts = 1 + solve(k + 1, s, dp); 
                mini = min(mini, cuts);
            }
        }
        return dp[i] = mini;
    }
public:
    int minCut(string s) {
        //Approach-1(Memoization Method-Top down dynamic programming)
        int n = s.size();
        vector<int> dp(n, -1); // Memoization table
        return solve(0, s, dp) - 1; // Subtract 1 because we count unnecessary cuts.
    }
};