class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        //Approach-1(Prefix Sum)
        int n=nums.size();
        vector<long long> suffixSum(n);
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            suffixSum[i]=sum;
        }
        int count=0;
        sum=0;
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            if(sum>=suffixSum[i+1])count++;
        }
        return count;
    }
};