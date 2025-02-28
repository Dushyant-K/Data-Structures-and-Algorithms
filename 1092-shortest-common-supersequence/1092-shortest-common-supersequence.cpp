class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //Approach-1(Tabulation method-Bottom up dynamic programming)
        int n1=str1.length();
        int n2=str2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    int l=dp[i-1][j];
                    int r = dp[i][j-1];
                    dp[i][j]=max(l,r);
                }
            }
        }

        string ans="";
        int i=n1;
        int j=n2;
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i][j-1]>dp[i-1][j]){//moving leftwards
            ans+=str2[j-1];
            j--;
            }
            else{//moving upwards
                ans+=str1[i-1];
                i--;
            }
        }

        //Taking what is remaining
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};