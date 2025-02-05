class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        //Approach-1
        if (s1 == s2) return true;
    
    vector<int> diffIndices;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            diffIndices.push_back(i);
            if (diffIndices.size() > 2) return false; // More than two mismatches
        }
    }
    
    if (diffIndices.size() != 2) return false;
    
    // Check if swapping the two differing indices makes them equal
    swap(s1[diffIndices[0]], s1[diffIndices[1]]);
    return s1 == s2;
    }
};