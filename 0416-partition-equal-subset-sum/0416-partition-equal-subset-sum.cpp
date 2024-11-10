class Solution {
    private:
    bool solve(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0)return true;
        if(idx==0){
            return (nums[0]==target);
        }

        if(dp[idx][target]!=-1)return dp[idx][target];

        //Take/notTake method
        bool notTake = solve(idx-1,target,nums,dp);
        bool take = false;
        if(target>=nums[idx]){
            take = solve(idx-1,target-nums[idx],nums,dp);
        }
        return dp[idx][target]=take||notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        //Approach-1(Memoization Method-Top Down dynamic programming)
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2==1)return false;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum/2,nums,dp);
    }
};