class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<string> palindromes;
        
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int first = -1, last = -1;
            
            // Find first and last occurrence of ch
            for (int i = 0; i < n; i++) {
                if (s[i] == ch) {
                    if (first == -1) first = i;
                    last = i;
                }
            }
            
            // If there's room for at least one character between first and last
            if (first != -1 && last != -1 && last > first + 1) {
                unordered_set<char> middle;
                for (int i = first + 1; i < last; i++) {
                    middle.insert(s[i]);
                }
                for (char mid : middle) {
                    palindromes.insert(string(1, ch) + mid + ch);
                }
            }
        }
        return palindromes.size();
    }
};
