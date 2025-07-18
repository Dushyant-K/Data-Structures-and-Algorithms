#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    static bool comparator(const string& log1, const string& log2) {
        stringstream ss1(log1), ss2(log2);
        string id1, id2;
        string word1, word2;

        ss1 >> id1;
        ss2 >> id2;

        string rest1 = log1.substr(log1.find(' ') + 1);
        string rest2 = log2.substr(log2.find(' ') + 1);

        // Check if log is digit-log or letter-log
        bool isDigit1 = isdigit(rest1[0]);
        bool isDigit2 = isdigit(rest2[0]);

        // Rule 1: letter-logs come before digit-logs
        if (!isDigit1 && isDigit2) return true;
        if (isDigit1 && !isDigit2) return false;

        // Rule 2: if both are letter-logs, sort by content, then identifier
        if (!isDigit1 && !isDigit2) {
            if (rest1 != rest2) return rest1 < rest2;
            return id1 < id2;
        }

        // Rule 3: digit-logs remain in original order
        return false;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        sort(logs.begin(), logs.end(), comparator);
        return logs;
    }
};
