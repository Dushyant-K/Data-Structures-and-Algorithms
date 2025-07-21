class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //Approach-1(Using Sliding Window and two pointer)
        int n = nums.size();

        int left=0;
        int right=0;
        int mini = INT_MAX;

        int sum = 0;
        while(right<n){
            sum+=nums[right];

            while(sum>=target){
                mini = min(mini,right-left+1);
                sum-=nums[left];
                left++;
            }
            right++;
        }

        if(mini==INT_MAX)return 0;
        return mini;
    }
};