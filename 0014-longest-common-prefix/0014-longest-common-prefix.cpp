class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
        return "";
    }

    string prefix = strs[0];
    
    for (size_t i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) {
            // Shorten the prefix
            prefix = prefix.substr(0, prefix.length() - 1);
            // If the prefix becomes empty, return an empty string
            if (prefix.empty()) {
                return "";
            }
        }
    }
    
    return prefix;
    }
};