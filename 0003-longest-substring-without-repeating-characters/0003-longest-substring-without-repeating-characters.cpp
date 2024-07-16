class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> charSet;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {
        // If character is already in the set, remove from start
        while (charSet.find(s[end]) != charSet.end()) {
            charSet.erase(s[start]);
            ++start;
        }
        
        // Add the current character to the set
        charSet.insert(s[end]);
        
        // Update the maximum length
        maxLength = std::max(maxLength, end - start + 1);
    }
    
    return maxLength;
    }
};