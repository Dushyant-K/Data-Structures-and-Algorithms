class Solution {
    private:
     int solve(int idx, int currSum, int target, vector<int>& nums, unordered_map<string,int>& mpp) {
        if (idx == nums.size()) {
            return currSum == target ? 1 : 0;
        }
        string str=to_string(idx)+"_"+to_string(currSum);
        if(mpp.count(str))return mpp[str];
        // Add the current number
        int add = solve(idx + 1, currSum + nums[idx], target, nums,mpp);

        // Subtract the current number
        int subtract = solve(idx + 1, currSum - nums[idx], target, nums,mpp);

        return mpp[str]=add + subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //Approach-1
        if (nums.empty()) return 0;
        int n=nums.size();

        unordered_map<string,int> mpp;
        return solve(0, 0, target, nums,mpp);
    }
};