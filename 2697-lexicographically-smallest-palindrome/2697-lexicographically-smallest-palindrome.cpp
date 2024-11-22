class Solution {
public:
    string makeSmallestPalindrome(string s) {
        //Approach-1(Two-Pointer)
        int n=s.size();
        int low=0;
        int high=n-1;
        while(low<high){
            if(s[low]==s[high]){
            }
            else{
                if(s[low]<=s[high]){
                    s[high]=s[low];
                }
                else{
                    s[low]=s[high];
                }
            }
            low++;
            high--;
        }
        return s;
    }
};