class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);
    
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0, rightSum = totalSum;
    
    for (int i = 0; i < n; i++) {
        rightSum -= nums[i];
        result[i] = (nums[i] * i - leftSum) + (rightSum - nums[i] * (n - i - 1));
        leftSum += nums[i];
    }
    
    return result;
    }
};