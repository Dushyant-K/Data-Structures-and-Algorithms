class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //Approach-1
        int prefixSum=0;
        int count=0;
        map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            int remove = prefixSum-goal;
            count+=mpp[remove];
            mpp[prefixSum]++;
        }
        return count;
    }
};