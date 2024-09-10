class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    //Approach-1
    int n = s.length();
    if(n==0)return 0;
    int maxLength=0;
    for(int i=0;i<n;i++){
        unordered_set<int> st;
        for(int j=i;j<n;j++){
           if(st.find(s[j])!=st.end()){
            break;
           }
           int length = (j-i+1);
            maxLength = max(length,maxLength);
           st.insert(s[j]);
        }
    }
    return maxLength;
    }
};