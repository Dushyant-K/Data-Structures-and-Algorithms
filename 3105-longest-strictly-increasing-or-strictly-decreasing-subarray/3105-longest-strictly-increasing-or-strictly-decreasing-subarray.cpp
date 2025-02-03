class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        //Approach-1
        // int n=nums.size();
        // int strictlyIncreasing=1;

        // int currLength=1;
        // for(int i=1;i<n;i++){
        //     if(nums[i]>nums[i-1]){
        //         currLength++;
        //     }
        //     else{
        //         strictlyIncreasing=max(strictlyIncreasing,currLength);
        //         currLength=1;
        //     }
        // }
        // strictlyIncreasing=max(strictlyIncreasing,currLength);


        // int strictlyDecreasing=1;

        // currLength=1;
        // for(int i=1;i<n;i++){
        //     if(nums[i]<nums[i-1]){
        //         currLength++;
        //     }
        //     else{
        //         strictlyDecreasing=max(strictlyDecreasing,currLength);
        //         currLength=1;
        //     }
        // }
        // strictlyDecreasing=max(strictlyDecreasing,currLength);

        // return max(strictlyIncreasing,strictlyDecreasing);

        //Approach-2(Optimal Approach)
        int n=nums.size();
        int increasing=1;
        int decreasing=1;

        int maxi=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                maxi=max(maxi,decreasing);
                decreasing=1;
                increasing++;
            }
            else if(nums[i]<nums[i-1]){
                maxi=max(maxi,increasing);
                increasing=1;
                decreasing++;
            }
            else{
                maxi=max(maxi,increasing);
                maxi=max(maxi,decreasing);
                increasing=1;
                decreasing=1;
            }
        }
        maxi=max(maxi,increasing);
        maxi=max(maxi,decreasing);
        return maxi;
    }
};