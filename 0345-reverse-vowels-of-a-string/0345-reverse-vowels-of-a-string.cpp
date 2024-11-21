class Solution {
public:
    string reverseVowels(string s) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int left = 0, right = s.length() - 1;

    while (left < right) {
        // Find the next vowel from the left
        while (left < right && vowels.find(s[left]) == vowels.end()) {
            left++;
        }
        // Find the next vowel from the right
        while (left < right && vowels.find(s[right]) == vowels.end()) {
            right--;
        }
        // Swap the vowels
        if (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    return s;
    }
};