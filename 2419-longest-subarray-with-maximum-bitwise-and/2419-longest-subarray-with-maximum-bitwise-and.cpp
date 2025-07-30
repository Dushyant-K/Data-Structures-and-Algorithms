class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //Approach-1(Using Bit Manipulation)
        int n = nums.size();

        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }

        int count=0;
        int maxCount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                count++;
                maxCount=max(count,maxCount);
            }else{
            count=0;
            }
        }

        return maxCount;
    }
};