class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Approach-1(stl-library)
        // next_permutation(nums.begin(),nums.end());

        //Approach-2()
        int n=nums.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }

        int low=idx+1;
        int high=n-1;
        while(low<high){
            int temp=nums[low];
            nums[low]=nums[high];
            nums[high]=temp;
        }
        return;
    }
};