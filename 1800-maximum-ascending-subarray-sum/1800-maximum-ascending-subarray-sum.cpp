class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        //Approach-1
        int  n=nums.size();
        int maxi=0;
        int sum=nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                sum+=nums[i];
            }
            else{
                maxi=max(maxi,sum);
                sum=nums[i];
            }
        }
        maxi=max(maxi,sum);
        return maxi;
    }
};