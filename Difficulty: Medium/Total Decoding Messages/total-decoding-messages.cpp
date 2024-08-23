//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	const int MOD = 1000000007;
		int CountWays(string s){
		    int n = s.length();
    if (n == 0) return 0;

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;  // An empty string has one way to decode

    for (int i = 1; i <= n; ++i) {
        // Single digit decode (s[i-1])
        if (s[i-1] >= '1' && s[i-1] <= '9') {
            dp[i] = (dp[i] + dp[i-1]) % MOD;
        }

        // Two digit decode (s[i-2]s[i-1])
        if (i > 1) {
            int twoDigit = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] = (dp[i] + dp[i-2]) % MOD;
            }
        }
    }

    return dp[n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends