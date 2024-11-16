class Solution {
    private:
    int solve(int idx, int prev_idx, vector<int> nums, vector<vector<int>>& dp,int n){
        // Base condition
    if (idx == n)
        return 0;
        
    if (dp[idx][prev_idx + 1] != -1)
        return dp[idx][prev_idx + 1];
    
    int notTake = 0 + solve(idx + 1, prev_idx,nums,dp,n);
    
    int take = 0;
    
    if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
        take = 1 + solve(idx + 1, idx,nums,dp,n);
    }
    
    return dp[idx][prev_idx + 1] = max(notTake, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        //Approach-1(Memoization Method-Top down dynamic Programming)
        // int n=nums.size();
        // for(int i=0;i<n;i++)mini=min(mini,nums[i]);
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solve(0,-1,nums,dp,n);

        //Approach-2(Tabulation method-Bottom up dynamic programming)
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
            int notTake = 0 + dp[ind+1][prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || nums[ind] > nums[prev_index]){
                
                take = 1 + dp[ind+1][ind+1];
            }
    
            dp[ind][prev_index+1] = max(notTake,take);
            
        }
    }
    
    return dp[0][0];
    }
};