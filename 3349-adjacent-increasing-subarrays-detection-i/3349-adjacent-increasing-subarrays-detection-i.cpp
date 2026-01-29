class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int len=1,prev=0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                len++;
            else {
                if (max(len / 2, min(len, prev)) >= k)
                    return 1;
                prev = len;
                len = 1;
            }
        }
        return max(len / 2, min(len, prev)) >= k;
    }
};