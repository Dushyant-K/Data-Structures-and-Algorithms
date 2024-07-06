class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       map<int,int>mpp;
       mpp[0]=1;
       int prefixSum=0,count=0;
       for(int i=0;i<nums.size();i++){
        prefixSum+=nums[i];
        int remove=prefixSum-k;
        count+=mpp[remove];
        mpp[prefixSum]+=1;
       } 
       return count;
    }
};