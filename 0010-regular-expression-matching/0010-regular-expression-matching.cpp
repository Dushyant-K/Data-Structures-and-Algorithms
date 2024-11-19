class Solution {
public:
    bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    
    // dp[i][j] will be true if s[0..i-1] matches p[0..j-1]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    
    // Base case: empty string matches empty pattern
    dp[0][0] = true;

    // Handle patterns with '*' that can match an empty sequence
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2]; // '*' can eliminate the preceding element
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                // If current characters match or pattern has '.'
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // '*' can either:
                // 1. Match zero of the preceding element (eliminate previous two in pattern)
                dp[i][j] = dp[i][j - 2];
                // 2. Match one or more of the preceding element (if they match)
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }

    return dp[m][n];
    }
};