class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        //Approach-1(Two-pointer Approach)
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int right=i+1;
                while(right<n&&nums[right]==0){
                    right++;
                }
                if(right==n)return nums;
                swap(nums[i],nums[right]);
            }
        }
        return nums;
    }
};