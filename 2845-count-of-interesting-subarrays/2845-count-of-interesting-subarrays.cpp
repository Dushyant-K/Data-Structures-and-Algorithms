class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, long long> mpp;

        long long ans = 0;
        int count = 0;

        mpp[0] = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] % modulo == k) count++;

            int curr = count % modulo;
            int need = (curr - k + modulo) % modulo;

            if (mpp.count(need)) {
                ans += mpp[need];
            }

            mpp[curr]++;
        }

        return ans;
    }
};
