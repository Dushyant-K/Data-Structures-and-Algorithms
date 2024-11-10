class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        //Approach-1
        sort(nums.begin(),nums.end());
        map<int,int>range;
        map<int,int>freq;
        int minRange=2e9;
        int maxRange=-2e9;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            int left = nums[i]-k;
            int right = nums[i]+k;
            minRange = min(minRange,left);
            maxRange = max(maxRange,right);
            range[left]++;
            range[right+1]--;
            range[nums[i]]+=0;
        }
        int ans=1;
        int previousRangeSum = 0;
        for(auto it:range){
            it.second+=previousRangeSum;
            previousRangeSum = it.second;
            int currElementFreq = freq[it.first];
            int maxFreq= it.second-currElementFreq;
            maxFreq = min(maxFreq,numOperations);
            maxFreq+=currElementFreq;
            ans = max(ans,maxFreq);
        }
        return ans;
    }
};