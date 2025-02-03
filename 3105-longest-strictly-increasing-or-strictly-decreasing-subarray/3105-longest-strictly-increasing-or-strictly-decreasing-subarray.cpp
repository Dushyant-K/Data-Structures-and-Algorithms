class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        //Approach-1
        int n=nums.size();
        int strictlyIncreasing=1;

        int currLength=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                currLength++;
            }
            else{
                strictlyIncreasing=max(strictlyIncreasing,currLength);
                currLength=1;
            }
        }
        strictlyIncreasing=max(strictlyIncreasing,currLength);


        int strictlyDecreasing=1;

        currLength=1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                currLength++;
            }
            else{
                strictlyDecreasing=max(strictlyDecreasing,currLength);
                currLength=1;
            }
        }
        strictlyDecreasing=max(strictlyDecreasing,currLength);

        return max(strictlyIncreasing,strictlyDecreasing);
    }
};