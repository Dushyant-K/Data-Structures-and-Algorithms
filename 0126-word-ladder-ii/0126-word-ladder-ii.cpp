class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //Approach-1
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return {};

        // BFS variables
        unordered_map<string, vector<string>> parent;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited; // Words visited in current level
        bool found = false;

        while (!q.empty() && !found) {
            int levelSize = q.size();
            visited.clear();

            for (int i = 0; i < levelSize; ++i) {
                string word = q.front();
                q.pop();

                string temp = word;
                for (int j = 0; j < word.size(); ++j) {
                    char originalChar = temp[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        temp[j] = c;

                        if (temp == endWord) {
                            found = true;
                            parent[temp].push_back(word);
                        }

                        if (wordSet.find(temp) != wordSet.end()) {
                            visited.insert(temp);
                            parent[temp].push_back(word);
                            q.push(temp);
                        }
                    }
                    temp[j] = originalChar;
                }
            }

            for (const auto& word : visited) {
                wordSet.erase(word);
            }
        }

        if (!found) return {};

        // Backtracking to build all paths
        vector<vector<string>> results;
        vector<string> path = {endWord};

        function<void(string)> backtrack = [&](string word) {
            if (word == beginWord) {
                reverse(path.begin(), path.end());
                results.push_back(path);
                reverse(path.begin(), path.end());
                return;
            }

            for (const string& p : parent[word]) {
                path.push_back(p);
                backtrack(p);
                path.pop_back();
            }
        };

        backtrack(endWord);
        return results;
    }
};