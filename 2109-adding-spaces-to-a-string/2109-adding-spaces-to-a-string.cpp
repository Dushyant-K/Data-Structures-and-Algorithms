class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        //Approach-1
        string result;
        int n = s.size();
        int m = spaces.size();
        int index = 0; 
        
        for (int i = 0; i < n; i++) {
            if (index < m && i == spaces[index]) {
                result += ' ';
                index++;
            }
            result += s[i];
        }
        
        return result;
    }
};