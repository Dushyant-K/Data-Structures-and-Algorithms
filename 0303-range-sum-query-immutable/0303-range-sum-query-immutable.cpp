class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.push_back(0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefixSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1]-prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */