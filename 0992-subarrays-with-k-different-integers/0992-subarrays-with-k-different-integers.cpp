class Solution {
public:
    int lessThanEqualTo(vector<int> nums, int k){
        int left =0;
        int right =0;
        map<int,int> mpp;
        int count=0;
        while(right<nums.size()){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)mpp.erase(nums[left]);
                left++;
            }
            count+= right-left+1;
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int sum1 = lessThanEqualTo(nums,k);
        int sum2 = lessThanEqualTo(nums,k-1);
        return (sum1-sum2);
    }
};