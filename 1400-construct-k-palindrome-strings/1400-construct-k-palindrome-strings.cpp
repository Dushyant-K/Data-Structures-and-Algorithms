class Solution {
public:
    bool canConstruct(string s, int k) {
    //Approach-1(Uses a property of palindrome)
    
     // If the string length is less than k, we can't form k palindromes
    if (s.size() < k) return false;

    // Count the frequency of each character
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Count characters with odd frequencies
    int oddCount = 0;
    for (auto& [key, count] : freq) {
        if (count % 2 != 0) {
            oddCount++;
        }
    }

    // Check if the number of odd frequencies is less than or equal to k
    return oddCount <= k;
    }
};