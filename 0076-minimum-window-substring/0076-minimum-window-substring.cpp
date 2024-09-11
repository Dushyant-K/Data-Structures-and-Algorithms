class Solution {
public:
    string minWindow(string s, string t) {
        //Approach-1
        // int minLength = (1e9);
        // int si=-1;
        // for(int i=0;i<s.size();i++){
        //     int hash[256]={0};
        //     int count=0;
        //     for(int j=0;j<t.size();j++){
        //         hash[t[j]]++;
        //     }
        //     for(int j=i;j<s.size();j++){
        //         if(hash[s[j]]>0)count++;
        //         hash[s[j]]--;
        //         if(count==t.size()){
        //             if(minLength>(j-i+1)){
        //                 minLength = (j-i+1);
        //                 si=i;
        //             }
        //             break;
        //         }
        //     }
        // }
        // if (si == -1) {
        //     return "";
        // }
        // return s.substr(si, minLength);

        //Approach-2
        int left=0;
        int right=0;
        int count=0;
        int minLength = INT_MAX;
        int si=-1;
        int n = s.size();
        int m = t.size();
        int hash[256]={0};
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(right<n){
            if(hash[s[right]]>0)count++;
            hash[s[right]]--;
            while(count==m){
                if(minLength>(right-left+1)){
                    minLength = right-left+1;
                    si=left;
                }
                hash[s[left]]++;
                if(hash[s[left]]>0)count--;
                left++;
            }
          right++;   
        }
        return (si==-1)?"":s.substr(si,minLength);
    }
};