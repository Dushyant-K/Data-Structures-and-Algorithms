class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //Approach-1
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set<string> st;
        for(int i=0;i<wordList.size();i++){
            st.insert(wordList[i]);
        }
        while(!q.empty()){
            string word = q.front().first;
            int moves = q.front().second;
            if(word==endWord){
                return moves;
            }
            q.pop();
            for(int i=0;i<word.size();i++){
                char originalChar = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,moves+1});
                    }
                }
                word[i]=originalChar;
            }
        }
        return 0;
    }
};