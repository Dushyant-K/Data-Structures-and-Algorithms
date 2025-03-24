class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left =0;
        int right = 0;
        int maxLength = 0;
        int count=0;
        while(right<n){
            if(nums[right]==0)count++;

          if(count>k){
            if(nums[left]==0)count--;
            left++;
          }

           int length = (right-left+1);
           maxLength = max(length,maxLength);
           right++;
        }
        return maxLength;
    }
};