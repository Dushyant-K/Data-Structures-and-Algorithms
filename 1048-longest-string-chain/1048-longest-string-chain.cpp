class Solution {
    private:
    bool checkPossibility(string word1, string word2){
        if (word1.length() < word2.length()) {
            swap(word1, word2); // Ensure word1 is always longer
        }
        int n1=word1.length();
        int n2=word2.length();
        if(n1-n2!=1)return false;
        int i=0;
        int j=0;
        int mismatch=0;
        while(i<n1&&j<n2){
            if(word1[i]==word2[j]){
                i++;
                j++;
            }
            else{
                mismatch++;
                i++;
                if(mismatch>1)return false;
            }
        }
        return true;
    }
    static bool comparator(const string& str1, const string& str2) {
        return str1.length() < str2.length();
    }
public:
    int longestStrChain(vector<string>& words) {
    //Approach-1(Most optimal Method)
    sort(words.begin(),words.end(), comparator);
    int n=words.size();
    vector<int> dp(n,1);
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(checkPossibility(words[i],words[j])){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
    }
};