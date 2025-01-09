class Solution {
public:
    int solve(int idx, vector<int>& nums, int& total) {
        // Base case: If there are fewer than 3 elements, return 0.
        if (idx < 2) return 0;

        int count = 0;

        // Check if the current triplet forms an arithmetic slice.
        if (nums[idx] - nums[idx - 1] == nums[idx - 1] - nums[idx - 2]) {
            count = 1 + solve(idx - 1, nums, total); // Extend previous slices.
            total += count; // Add to the total count.
        } else {
            solve(idx - 1, nums, total); // Move to the next element without incrementing the count.
        }

        return count;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        //Approach-1(Memoization - Top down dynamic programming)
        // int n = nums.size();
        // if (n < 3) return 0; // No arithmetic slices possible.

        // int total = 0; // Total count of arithmetic slices.
        // solve(n - 1, nums, total); // Start recursion from the last index.
        // return total;

        //Approach-2(Tabulation - Bottom up dynamic programming)
        int n = nums.size();
        if (n < 3) return 0; // No arithmetic slices possible.

        vector<int> dp(n+1,0);

        int total=0;
        for(int i=2;i<n;i++){
            int count=0;
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                count=1+dp[i-1];
            }
            total+=count;
            dp[i]=count;
        }
        return total;
    }
};
