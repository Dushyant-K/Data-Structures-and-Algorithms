class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    //Approach-1(Kadane's Algorithm)
    int n = nums.size();
    int sum=0;
    int maxSum=INT_MIN;
    int left=0;
    int right=0;
    while(right<n){
        sum+=nums[right];
        maxSum = max(maxSum,sum);
        while(sum<0&&left<=right){
            sum-=nums[left];
            left++;
        }
        right++;
    }
    //Approach-1
    //  int maxSum=nums[0];
    //  int sum=0;
    //  int start=0;
    //  int end=0;
    //  for(int i=0;i<nums.size();i++){
    //     sum+=nums[i];
    //     if(sum>maxSum){
    //         maxSum=sum;
    //         // end=i;
    //     }
    //     if(sum<0){
    //         sum=0;
    //         // start=i;
    //     }
    //  }   
     return maxSum;
    }
};