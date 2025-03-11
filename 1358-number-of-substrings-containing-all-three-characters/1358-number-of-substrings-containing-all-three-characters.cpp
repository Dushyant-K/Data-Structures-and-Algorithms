class Solution {
public:
    int numberOfSubstrings(string s) {
        //Approach-1
        // int n =s.length();
        // int count=0;
        // for(int i=0;i<n;i++){
        //     int hash[3]={0};
        //     for(int j=i;j<n;j++){
        //         hash[s[j]-'a']++;
        //         if((hash[0]!=0)&&(hash[1]!=0)&&(hash[2]!=0)){
        //             count+=n-j;
        //             break;
        //         }
        //     }
        // }
        // return count;

        //Approach-2
        int count=0;
        int hash[3];
        for(int i=0;i<=2;i++){
            hash[i]=-1;
        }
        for(int i=0;i<s.length();i++){
            hash[s[i]-'a']=i;
            if((hash[0]!=-1)&&(hash[1]!=-1)&&(hash[2]!=-1)){
                count+=min(hash[0],min(hash[1],hash[2]))+1;
            }
        }
        return count;
    }
};