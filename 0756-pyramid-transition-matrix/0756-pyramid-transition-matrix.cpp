class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string bottom,
               unordered_map<string, vector<char>>& patterns) {

        // Base case: pyramid completed
        if (bottom.length() == 1)
            return true;

        // Memo check
        if (memo.count(bottom))
            return memo[bottom];

        int n = bottom.length();

        // Generate all possible upper rows using DFS
        function<bool(int, string&)> dfs = [&](int idx, string& curr) {
            if (idx == n - 1) {
                return solve(curr, patterns);
            }

            string key = bottom.substr(idx, 2);
            if (!patterns.count(key))
                return false;

            for (char ch : patterns[key]) {
                curr.push_back(ch);
                if (dfs(idx + 1, curr))
                    return true;
                curr.pop_back();
            }
            return false;
        };

        string curr = "";
        bool res = dfs(0, curr);
        memo[bottom] = res;
        return res;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> patterns;

        for (auto& s : allowed) {
            patterns[s.substr(0, 2)].push_back(s[2]);
        }

        return solve(bottom, patterns);
    }
};
