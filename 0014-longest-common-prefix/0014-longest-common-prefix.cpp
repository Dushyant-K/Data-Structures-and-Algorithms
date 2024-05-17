class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
        return "";
    }
    
    // Assume the first string is the common prefix
    string prefix = strs[0];
    
    // Compare the prefix with each string in the array
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