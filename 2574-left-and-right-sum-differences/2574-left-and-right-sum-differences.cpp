class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        //Approach-1(Optimal)
        int n=nums.size();
        int suffixSum = accumulate(nums.begin(),nums.end(), 0);

        vector<int> ans;
        int prefixSum=0;

        for(int i=0;i<n;i++){
            suffixSum-=nums[i];
            ans.push_back(abs(prefixSum-suffixSum));
            prefixSum+=nums[i];
        }

        return ans;
    }
};