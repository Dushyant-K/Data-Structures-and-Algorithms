class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        return mergeSort(prefixSum, 0, n + 1, lower, upper);
    }

    int mergeSort(vector<long long>& sum, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        
        int mid = (left + right) / 2;
        int count = mergeSort(sum, left, mid, lower, upper) + mergeSort(sum, mid, right, lower, upper);

        int j = mid, k = mid, t = mid;
        vector<long long> cache;
        int r = 0;

        for (int i = left; i < mid; ++i) {
            // Count valid range sums
            while (k < right && sum[k] - sum[i] < lower) k++;
            while (j < right && sum[j] - sum[i] <= upper) j++;
            count += (j - k);

            // Merge step: maintain sorted order
            while (t < right && sum[t] < sum[i]) cache.push_back(sum[t++]);
            cache.push_back(sum[i]);
        }

        // Copy remaining elements from right half
        while (t < right) cache.push_back(sum[t++]);

        // Copy back to original array
        for (int i = left; i < left + cache.size(); ++i) {
            sum[i] = cache[i - left];
        }

        return count;
    }
};
