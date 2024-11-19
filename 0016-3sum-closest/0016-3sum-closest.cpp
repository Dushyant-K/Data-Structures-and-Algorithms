class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
            // Sort the array
    sort(nums.begin(), nums.end());

    int closestSum = INT_MAX / 2; // Initialize with a large value

    for (int i = 0; i < nums.size() - 2; ++i) {
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // Update closestSum if currentSum is closer to target
            if (abs(target - currentSum) < abs(target - closestSum)) {
                closestSum = currentSum;
            }

            // Adjust pointers based on the sum
            if (currentSum < target) {
                ++left;
            } else if (currentSum > target) {
                --right;
            } else {
                // Exact match found
                return currentSum;
            }
        }
    }

    return closestSum;
    }
};