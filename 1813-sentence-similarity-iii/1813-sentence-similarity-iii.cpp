class Solution {
    private:
    // Utility function to split a sentence into words
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        //Approach-1(Two-Pointer Approach)
        // Ensure sentence1 is always the shorter one
        if (sentence1.size() > sentence2.size()) {
            swap(sentence1, sentence2);
        }

        vector<string> words1 = split(sentence1, ' ');
        vector<string> words2 = split(sentence2, ' ');

        int left = 0, right1 = words1.size() - 1, right2 = words2.size() - 1;

        // Match words from the beginning
        while (left < words1.size() && words1[left] == words2[left]) {
            left++;
        }

        // Match words from the end
        while (right1 >= left && right2 >= left && words1[right1] == words2[right2]) {
            right1--;
            right2--;
        }

        // Check if all words in sentence1 are accounted for
        return left > right1;
    }
};