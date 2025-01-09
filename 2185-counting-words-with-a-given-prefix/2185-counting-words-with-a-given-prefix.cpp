class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        //Approach-1(Two-Poiner Approach)
        int n =pref.size();

        int count=0;
        for(auto str:words){
            int n1=str.length();
            if(n1<n)continue;

            string prefix=str.substr(0,n);
            if(prefix==pref)count++;
        }
        return count;
    }
};