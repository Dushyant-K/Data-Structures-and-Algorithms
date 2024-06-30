class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int maxSum=nums[0];
     int sum=0;
     int start=0;
     int end=0;
     for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum>maxSum){
            maxSum=sum;
            // end=i;
        }
        if(sum<0){
            sum=0;
            // start=i;
        }
     }   
     return maxSum;
    }
};