class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
         for (char c : s) {
            if (isalnum(c)) { // Check if the character is alphanumeric
                filtered += tolower(c); // Convert to lowercase and add to filtered string
            }
        }
        
        // Check if the filtered string is a palindrome
        int left = 0, right = filtered.length() - 1;
        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false; // Not a palindrome
            }
            left++;
            right--;
        }
        
        return true; // It is a palindrome
    }
};