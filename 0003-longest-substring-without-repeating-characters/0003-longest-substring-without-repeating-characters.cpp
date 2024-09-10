class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    //Approach-1
    // int n = s.length();
    // if(n==0)return 0;
    // int maxLength=0;
    // for(int i=0;i<n;i++){
    //     unordered_set<int> st;
    //     for(int j=i;j<n;j++){
    //        if(st.find(s[j])!=st.end()){
    //         break;
    //        }
    //        int length = (j-i+1);
    //         maxLength = max(length,maxLength);
    //        st.insert(s[j]);
    //     }
    // }
    // return maxLength;

    //Approach-
    
    int n = s.length();
    int l =0;
    int r =0;
    int maxLength = 0;
    int hash[256];
    fill(begin(hash), end(hash), -1);
    while(r<n){
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
                l = hash[s[r]]+1;
            }
        }
        int length = (r-l+1);
        maxLength = max(length,maxLength);
        hash[s[r]] = r;
        r++;
    }
    return maxLength;
    }
};