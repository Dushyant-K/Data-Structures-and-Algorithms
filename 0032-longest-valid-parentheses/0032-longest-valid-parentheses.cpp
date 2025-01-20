class Solution {
public:
    int longestValidParentheses(string s) {
    stack<int> st;
    int maxLength = 0;
    st.push(-1); // Base for valid substring calculations

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i); // Push the index of '('
        } else {
            st.pop(); // Pop for a potential match
            if (st.empty()) {
                st.push(i); // Update the base for the next valid substring
            } else {
                maxLength = max(maxLength, i - st.top()); // Update max length
            }
        }
    }

    return maxLength;
    }
};