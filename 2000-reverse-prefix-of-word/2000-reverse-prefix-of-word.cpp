class Solution {
public:
    string reversePrefix(string word, char ch) {
        //Approach-1
        int n=word.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                idx=i;
                break;
            }
        }
        if(idx==-1)return word;
        reverse(word.begin(),word.begin()+idx+1);
        return word;
    }
};