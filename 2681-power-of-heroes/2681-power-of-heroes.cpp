class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        int sum = 0;

        long long subsets = (1LL << n); // Use long long to prevent overflow
        for(long long i = 1; i < subsets; i++) { // Ensure 'i' is long long
            int maxi = INT_MIN;
            int mini = INT_MAX;

            for(int j = 0; j < n; j++) {
                if(i & (1LL << j)) { // Ensure bit shift works correctly
                    maxi = max(maxi, nums[j]);
                    mini = min(mini, nums[j]);
                }
            }
            sum = (sum + ((1LL * maxi * maxi % mod) * mini) % mod) % mod;
        }

        return sum;
    }
};
