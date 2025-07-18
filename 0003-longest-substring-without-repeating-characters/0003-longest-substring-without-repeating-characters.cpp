class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Approach-1(Two Pointer Approach)
        int n = s.length();
        if(n==0)return 0;

        vector<int> arr(256,-1);
        int maxi = 1;

        int left=0;
        int right=0;
        while(right<n){
            char ch = s[right];
           if(arr[ch] >= left) {
                left = arr[ch] + 1;
            }

            arr[ch]=right;

            maxi = max(maxi, right-left+1);
            right++;
        }

        return maxi;
    }
};