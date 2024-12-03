class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        //Approach-1
        stringstream ss(sentence);
        string word;
        int index=1;
        while(ss>>word){
            if(word.length()<searchWord.length()){
                index++;
                continue;
            }
            if(word.find(searchWord)==0)return index;
            index++;
        }
        return -1;
    }
};