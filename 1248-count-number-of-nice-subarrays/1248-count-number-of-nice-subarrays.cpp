class Solution {
public:
    int sumLessThanEqualToK(const vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = 0; // Count of subarrays with at most k odd numbers
        int oddCount = 0; // Count of odd numbers in the current window

        while (right < nums.size()) {
            if (nums[right] % 2 != 0) {
                oddCount++; // Increment if the current number is odd
            }

            while (oddCount > k) { // When odd count exceeds k, move the left pointer
                if (nums[left] % 2 != 0) {
                    oddCount--; // Decrement the odd count when the number at left is odd
                }
                left++;
            }

            count += (right - left + 1); // Count all subarrays ending at `right` with at most k odd numbers
            right++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum1 = sumLessThanEqualToK(nums, k); // Subarrays with at most k odd numbers
        int sum2 = sumLessThanEqualToK(nums, k - 1); // Subarrays with at most (k - 1) odd numbers
        return (sum1 - sum2); // Subarrays with exactly k odd numbers
    }
};
