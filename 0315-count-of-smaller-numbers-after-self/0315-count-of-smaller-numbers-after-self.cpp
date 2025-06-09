class Solution {
public:
    void merge(vector<pair<int, int>>& nums, vector<int>& count, int low, int mid, int high) {
        vector<pair<int, int>> temp;
        int p1 = low, p2 = mid + 1;

        while (p1 <= mid && p2 <= high) {
            if (nums[p1].first <= nums[p2].first) {
                temp.push_back(nums[p2]);
                p2++;
            } else {
                // nums[p1].first > nums[p2].first
                // All elements from p2 to high are smaller than nums[p1]
                count[nums[p1].second] += (high - p2 + 1);
                temp.push_back(nums[p1]);
                p1++;
            }
        }

        while (p1 <= mid) temp.push_back(nums[p1++]);
        while (p2 <= high) temp.push_back(nums[p2++]);

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mergeSort(vector<pair<int, int>>& nums, vector<int>& count, int low, int high) {
        if (low >= high) return;

        int mid = (low + high) / 2;
        mergeSort(nums, count, low, mid);
        mergeSort(nums, count, mid + 1, high);
        merge(nums, count, low, mid, high);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; ++i)
            numsWithIndex.push_back({nums[i], i});

        vector<int> count(n, 0);
        mergeSort(numsWithIndex, count, 0, n - 1);
        return count;
    }
};
