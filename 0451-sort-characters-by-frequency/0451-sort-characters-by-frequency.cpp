class Solution {
public:  
    string frequencySort(string s) {
        //Approach-1
        map<char, int> mpp;
        // Build the frequency map
        for (char c : s) {
            mpp[c]++;
        }
        
        // Sort string based on frequency of characters
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (mpp[a] == mpp[b]) {
                return a < b;  // If frequencies are the same, maintain lexicographical order
            }
            return mpp[a] > mpp[b];  // Sort in descending order of frequency
        });
        
        return s;
    }
};