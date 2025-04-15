class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Approach-1
        // int n = nums.size();
        // int ans=0;

        // for(int i=0;i<=31;i++){
        //     int count=0;
        //     for(int j=0;j<n;j++){
        //         if(nums[j]&(1<<i))count++;
        //     }

        //     if(count%3==1)ans =  ans|(1<<i);
        // }

        // return ans;

        //Approach-2(Sorting)
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i+=3){
            if(nums[i]!=nums[i-1])return nums[i-1];
        }

        return nums[n-1];
    }
};