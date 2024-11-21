class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        //Approach-1
        int n=nums.size();
        vector<int> prefixSum(n,0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int mini = max(0, i - k);
                int maxi = min(n - 1, i + k);
                prefixSum[mini]++;
                if (maxi + 1 < n) {
                    prefixSum[maxi + 1]--;
                }
            }
        }
        int sum=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            sum+=prefixSum[i];
            prefixSum[i]=sum;
            if(prefixSum[i]>0)ans.push_back(i);
        }
        return ans;
    }
};