class Solution {
public:
    int solve(int idx, string&s, int n){
        if(idx==n)return 1;
        if(s[idx]=='0')return 0;

        //Don't Club it
        int left=solve(idx+1,s,n);
        //Club it
        int right=0;
         if (idx < n-1 && stoi(s.substr(idx, 2)) <= 26) {
            right = solve(idx + 2, s, n);
        }

        return left+right;
    }
    int numDecodings(string s) {
        //Approach-1(Recursion backtracking)
        int n=s.length();
        return solve(0,s,n);
    }
};