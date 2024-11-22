class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        //Approach-1(Two-pointer)
        int n1=str1.size();
        int n2=str2.size();
        if(n1<n2)return false;

        int left=0;
        int right=0;
        while(left<n1&&right<n2){
        int diff=str2[right]-str1[left];
           if(diff==0||diff==1||diff==-25){
            left++;
            right++;
           }
           else{
            left++;
           }
        }

        if(right==n2)return true;
        return false;
    }
};