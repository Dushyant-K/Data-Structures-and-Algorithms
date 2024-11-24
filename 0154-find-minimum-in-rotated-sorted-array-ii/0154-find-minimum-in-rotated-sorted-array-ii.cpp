class Solution {
public:
    int findMin(vector<int>& nums) {
        //Approach-1(Binary Search)
        int n=nums.size();
        int ans=INT_MAX;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]==nums[mid]&&nums[mid]==nums[high])
            {
                ans=min(ans,nums[low]);
                low++;
                high--;
                continue;
            }
            else if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};