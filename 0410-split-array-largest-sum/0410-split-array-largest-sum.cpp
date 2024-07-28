class Solution {
public:
    int count(vector<int> nums, int capacity){
        int parts =1;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+sum<=capacity){
                sum+=nums[i];
            }
            else{
                parts++;
                sum = nums[i];
            }
        }
        return parts;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid = (low+high)/2;
            int countParts = count(nums,mid);
            if(countParts>k){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return low;
    }
};