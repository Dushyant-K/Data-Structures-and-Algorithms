class Solution {
public:

void generateParenthesisHelper(int n, int open, int close, string current, vector<string> &result) {
    // If the current string is of length 2*n, it is a valid combination
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // If we can add an open parenthesis, add it and recurse
    if (open < n) {
        generateParenthesisHelper(n, open + 1, close, current + "(", result);
    }

    // If we can add a close parenthesis, add it and recurse
    if (close < open) {
        generateParenthesisHelper(n, open, close + 1, current + ")", result);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> result;
    generateParenthesisHelper(n, 0, 0, "", result);
    return result;
    }
};