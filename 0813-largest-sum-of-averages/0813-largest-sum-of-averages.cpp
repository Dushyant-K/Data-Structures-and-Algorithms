class Solution {
    private:
    double solve(int idx, int k ,vector<int>& nums, vector<vector<double>>& dp){
        if(idx<0)return 0.0;
        if(k==0){
            return INT_MIN;
        }
        if(dp[idx][k]!=-1.0)return dp[idx][k];
        double maxScore=0;
        double sum=0;
        for(int i=idx;i>=0;i--){
            sum+=nums[i];
            maxScore=max(maxScore,(sum/(idx-i+1))+solve(i-1,k-1,nums,dp));
        }
        return dp[idx][k]=maxScore;
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        //Approach-1(Recursion-backtracking)
        int n=nums.size();
        vector<vector<double>> dp(n+1,vector<double>(k+1,-1.0));
        return solve(n-1,k,nums,dp);
    }
};