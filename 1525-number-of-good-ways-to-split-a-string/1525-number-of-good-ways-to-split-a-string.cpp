class Solution {
public:
    int numSplits(string s) {
        //Approach-1
       int n=s.size();
        map<char,int>m1;
        map<char,int>m2;

        for(auto it:s) m1[it]++;
        int ans=0;
        for(int i=0; i<n; i++){
            char a=s[i];
            m2[a]++;
            m1[a]--;
            if(m1[a]==0) m1.erase(a);
            if(m1.size()==m2.size()) ans++;
        }

        return ans;
    }
};