class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //Approach-1
         if (s.length() != t.length()) return false;
        
        unordered_map<char, char> map_s_to_t;
        unordered_map<char, char> map_t_to_s;

        for (int i = 0; i < s.length(); ++i) {
            char s_char = s[i];
            char t_char = t[i];
            
            // Check if there's a mapping from s_char to t_char
            if (map_s_to_t.find(s_char) != map_s_to_t.end()) {
                if (map_s_to_t[s_char] != t_char) return false;
            } else {
                map_s_to_t[s_char] = t_char;
            }

            // Check if there's a mapping from t_char to s_char
            if (map_t_to_s.find(t_char) != map_t_to_s.end()) {
                if (map_t_to_s[t_char] != s_char) return false;
            } else {
                map_t_to_s[t_char] = s_char;
            }
        }

        return true;
    }
};