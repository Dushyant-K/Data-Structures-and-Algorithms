class Solution {
public:
    string customSortString(string order, string s) {
        //Approach-1(Custom sort)
        int hash[26]={100};
        int n1=order.size();
        for(int i=0;i<n1;i++){
            hash[order[i]-'a']=i;
        }

        sort(s.begin(),s.end(),[&](char a, char b){
            if(hash[a-'a']<hash[b-'a'])return true;
            return false;
        });
        return s;
    }
};