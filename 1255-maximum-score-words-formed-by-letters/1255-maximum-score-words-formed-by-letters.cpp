class Solution {
public:
    int solve(int idx, vector<string>& words, vector<int>& freq, vector<int>& score, int currScore, int n){
        if(idx==n){
            return currScore;
        }

        //Can we even take this element or not
        int tempScore=0;
        vector<int> tempFreq=freq;
        int i;
        for(i=0;i<words[idx].length();i++){
            char ch=words[idx][i];
            if(tempFreq[ch-'a']==0)break;
            tempFreq[ch-'a']--;
            tempScore+=score[ch-'a'];
        }
        int take=0;
        if(i==words[idx].length()){
            take=solve(idx+1,words,tempFreq,score,currScore+tempScore,n);
        }

        //If we dont take the word
        int not_take=solve(idx+1,words,freq,score,currScore,n);

        return max(take,not_take);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
       //Approach-1(Recursion backtracking)
       int n=words.size();
       vector<int> freq(26,0);
       for(auto it:letters){
        freq[it-'a']++;
       } 

       return solve(0,words,freq,score,0,n);
    }
};