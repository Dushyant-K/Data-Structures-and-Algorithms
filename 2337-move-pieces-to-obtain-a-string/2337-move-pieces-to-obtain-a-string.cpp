class Solution {
public:
    bool canChange(string start, string target) {
    int n = start.length();
    
    // Remove all '_' and compare the remaining characters
    string s1, t1;
    for (char c : start) {
        if (c != '_') s1 += c;
    }
    for (char c : target) {
        if (c != '_') t1 += c;
    }
    if (s1 != t1) return false;

    // Check for valid movement of 'L' and 'R'
    int i = 0, j = 0;
    while (i < n && j < n) {
        // Skip blanks in both strings
        while (i < n && start[i] == '_') i++;
        while (j < n && target[j] == '_') j++;

        // If both pointers are out of bounds, we are done
        if (i == n && j == n) return true;
        
        // If one pointer is out of bounds, but not the other, it's invalid
        if (i == n || j == n) return false;

        // Check if positions and rules for 'L' and 'R' are valid
        if (start[i] != target[j]) return false;
        if (start[i] == 'L' && i < j) return false;
        if (start[i] == 'R' && i > j) return false;

        i++;
        j++;
    }
    
    return true;
    }
};