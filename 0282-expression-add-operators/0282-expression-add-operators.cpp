class Solution {
public:
    void solve(int idx, string expr, long prev, long curr, string& num, int target, vector<string>& result) {
        if (idx == num.size()) {
            if (curr == target) {
                result.push_back(expr);
            }
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') break;  // Skip leading zero numbers

            string part = num.substr(idx, i - idx + 1);
            long val = stol(part);

            if (idx == 0) {
                solve(i + 1, expr + part, val, val, num, target, result);
            } else {
                solve(i + 1, expr + "+" + part, val, curr + val, num, target, result);
                solve(i + 1, expr + "-" + part, -val, curr - val, num, target, result);
                solve(i + 1, expr + "*" + part, prev * val, curr - prev + (prev * val), num, target, result);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        solve(0, "", 0, 0, num, target, result);
        return result;
    }
};
