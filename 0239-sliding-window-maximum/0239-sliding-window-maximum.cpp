class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Approach-1
        // int n = nums.size();
        // vector<int> ans;
        // for(int i=0;i<=n-k;i++){
        //     int maxi = nums[i];
        //     for(int j=i;j<=(i+k-1);j++){
        //         maxi = max(maxi,nums[j]);
        //     }
        //     ans.push_back(maxi);
        // }
        // return ans;

        //Approach-2
        deque<int> dq;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!(dq.empty())&&(dq.front()<(i-k+1))){
                dq.pop_front();
            }
            while(!(dq.empty())&&(nums[dq.back()]<=nums[i])){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=(k-1))ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};