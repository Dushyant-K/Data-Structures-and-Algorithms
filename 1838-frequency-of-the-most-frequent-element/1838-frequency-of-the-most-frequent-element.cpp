class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        //Approach-1(Sliding Window and two pointer approach)
        int  n = nums.size();
        sort(nums.begin(),nums.end());

        int left=0;
        int right=0;
        int total=0;
        int maxFreq = 1;

        while(right<n){
            total+=nums[right];
            while((long long)nums[right]*(right-left+1)>total+k){
                total-=nums[left];
                left++;
            }
            maxFreq = max(maxFreq,right-left+1);
            right++;
        }

        return maxFreq;
    }
};