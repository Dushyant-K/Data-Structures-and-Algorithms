class Solution {
public:
   void backtrack(string& s, int i, string temp, vector<string>& ans) {
        if (i == s.size()) {
            ans.push_back(temp);
            return;
        }
        
        if (isalpha(s[i])) {
            temp.push_back(tolower(s[i]));
            backtrack(s, i + 1, temp, ans);
            temp.pop_back();

            temp.push_back(toupper(s[i]));
            backtrack(s, i + 1, temp, ans);
            temp.pop_back();
        } else {
            temp.push_back(s[i]);
            backtrack(s, i + 1, temp, ans);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtrack(s, 0, "", ans);
        return ans;
    }
};