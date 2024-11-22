class Solution {
public:
    int countBinarySubstrings(string s) {
       //Approach-1
       vector<int> groups;
       int count=1;
       for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
            groups.push_back(count);
            count=1;
        }
        else count++;
       }
       groups.push_back(count);
       int maxCount=0;
       for(int i=1;i<groups.size();i++){
        maxCount+=min(groups[i],groups[i-1]);
       }
       return maxCount;
    }
};