class Solution {
public:
    int minimumLength(string s) {
        //Approach-1
        int n=s.length();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        int minLength=0;
        for(int i=0;i<=25;i++){
            if(freq[i]==0)continue;

            if(freq[i]%2==0)minLength+=2;
            else minLength+=1;
        }

        return minLength;
    }
};