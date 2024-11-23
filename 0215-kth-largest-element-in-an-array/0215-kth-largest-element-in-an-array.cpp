class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Approach-1(Sorting Approach)
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=0;i--){
            k--;
            if(k==0)return nums[i];
        }
        return -1;
    }
};