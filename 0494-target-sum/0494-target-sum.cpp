class Solution {
    private:
     int solve(int idx, int currSum, int target, vector<int>& nums) {
        if (idx == nums.size()) {
            return currSum == target ? 1 : 0;
        }

        // Add the current number
        int add = solve(idx + 1, currSum + nums[idx], target, nums);

        // Subtract the current number
        int subtract = solve(idx + 1, currSum - nums[idx], target, nums);

        return add + subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //Approach-1
        if (nums.empty()) return 0;
        return solve(0, 0, target, nums);
    }
};