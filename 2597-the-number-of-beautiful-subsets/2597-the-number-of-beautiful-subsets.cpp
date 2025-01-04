class Solution {
public:
    int solve(int idx, vector<int>& nums, unordered_map<int, int>& freq, int k, int n) {
        if (idx == n) {
            return 1;  // Count this subset
        }

        // Not taking the element at idx
        int not_take = solve(idx + 1, nums, freq, k, n);

        // Taking the element if valid
        int take = 0;
        if (freq[nums[idx] + k] == 0 && freq[nums[idx] - k] == 0) {
            freq[nums[idx]]++;
            take = solve(idx + 1, nums, freq, k, n);
            freq[nums[idx]]--;  // Backtrack
        }

        return take + not_take;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        return solve(0, nums, freq, k, n) - 1;  // Subtract 1 to exclude the empty subset
    }
};
