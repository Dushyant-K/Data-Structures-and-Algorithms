class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Approach-1(Using Prefix Sum Approach)
        int n = nums.size();

        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.find(sum%k)!=mpp.end()){
                if(i-mpp[sum%k]+1>=2)return true;
            }else{
                mpp[sum%k]=i;
            }
        }

        return false;

    }
};