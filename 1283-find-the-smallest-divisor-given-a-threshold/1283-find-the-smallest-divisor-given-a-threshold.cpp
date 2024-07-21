class Solution {
public:

    int isPossible(vector<int> nums, int divisor, int threshold){
        int sum =0;
        int n =nums.size();
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/(double)divisor);
        }
        if(sum<=threshold)return 1;

        return 0;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        int low=1;
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(nums,mid,threshold)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};