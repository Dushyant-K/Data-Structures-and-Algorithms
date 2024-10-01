class Solution {
public:
    bool rotateString(string s, string goal) {
        //Approach-1
         if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenate s with itself
        string concatenated = s + s;
        
        // Check if goal is a substring of the concatenated string
        return concatenated.find(goal) != string::npos;
    }
};