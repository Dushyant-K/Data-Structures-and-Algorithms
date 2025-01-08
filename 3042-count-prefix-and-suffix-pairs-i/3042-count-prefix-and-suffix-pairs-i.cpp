class Solution {
public:
    int isPrefixAndSuffix(string str1, string str2){
        int n1=str1.length();
        int n2=str2.length();

        if(n2<n1)return false;

        int i=0,j=0;
        while(i<n1&&j<n2){
            if(str1[i]!=str2[j])return false;
            i++;
            j++;
        }

        i=n1-1;
        j=n2-1;
        while(i>=0&&j>=0){
            if(str1[i]!=str2[j])return false;
            i--;
            j--;
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        //Approach-1
        int n=words.size();
        int count=0;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j]))count++;
            }
        }
        return count;
    }
};