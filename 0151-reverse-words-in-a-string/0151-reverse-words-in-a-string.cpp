class Solution {
public:
    string reverseWords(string s) {
    stringstream iss(s);
    string word;
    vector<std::string> words;

    // Split the string into words using a stringstream
        //Approach-1
        while (iss >> word) {
        words.push_back(word);
    }

    // Reverse the vector of words
   reverse(words.begin(), words.end());

    // Join the reversed words into a single string with one space between each word
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) {
            result += " ";  // Add space between words, but not at the end
        }
    }

    return result;
    }
};