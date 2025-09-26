class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Approach-1(Using Map)
        int n = nums.size();
        map<int,int> mpp;

        vector<int> ans;
        int left=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            if(i>=k-1){
                auto it = prev(mpp.end());
                ans.push_back(it->first);

                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)mpp.erase(nums[left]);
                left++;
            }
        }
        return ans;
    }
};