class Solution {
public:
    void solve(int idx, vector<string>& keypad, string& digits, int& n,
               vector<string>& ans, string ds) {
        if (idx == n) {
            ans.push_back(ds);
            return;
        }

        string letters = keypad[digits[idx] - '0'];

        for (int i = 0; i < letters.size(); i++) {
            ds.push_back(letters[i]);
            solve(idx + 1, keypad, digits, n, ans, ds);
            ds.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        // Approach-1(Using Recursion)
        vector<string> keypad = {"",    "",    "abc",  "def", "ghi",
                                 "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        int n = digits.length();
        solve(0, keypad, digits, n, ans, "");

        return ans;
    }
};