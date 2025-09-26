class Solution {
public:
    string removeKdigits(string num, int k) {
       stack<char> st;
        int n = num.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // If still k > 0, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty()) return "0";

        // Build the number from stack
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Reverse since we built from stack
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while (i < (int)ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};