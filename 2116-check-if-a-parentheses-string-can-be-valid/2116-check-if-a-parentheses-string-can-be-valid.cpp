class Solution {
public:
    bool solve(int idx, int count, string s, string locked, int n){
        if(idx==n){
            return count==0;
        }

        bool take=false;
        bool not_take=false;
        if(s[idx]=='('){
            take=solve(idx+1,count+1,s,locked,n);
            not_take=solve(idx+1,count-1,s,locked,n);
        }
        else{
            take=solve(idx+1,count-1,s,locked,n);
            not_take=solve(idx+1,count+1,s,locked,n);
        }

        return take||not_take;
    }
    bool canBeValid(string s, string locked) {
        // //Approach-1(Recursion - Leap of faith)
        // int n=s.length();

        // return solve(0,0,s,locked,n);

        //Approach-2
        int n = s.size();
        if (n % 2 != 0) return false; // Odd length cannot form a valid string.

        int balance = 0;
        // Left-to-right pass
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0' || s[i] == '(') {
                balance++; // Treat unlocked or '(' as potential opening brackets
            } else {
                balance--; // Closing bracket
            }
            if (balance < 0) return false; // Too many closing brackets
        }

        balance = 0;
        // Right-to-left pass
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')') {
                balance++; // Treat unlocked or ')' as potential closing brackets
            } else {
                balance--; // Opening bracket
            }
            if (balance < 0) return false; // Too many opening brackets
        }

        return true;
    }
};