class Solution {
    private:
    int solve(int idx, int arr[], vector<int>& dp){
        if(idx==0)return arr[0];
        if(idx<0)return 0;
        
        if(dp[idx]!=-1)return dp[idx];
        
        //Take and Not take method
        int take = arr[idx]+solve(idx-2,arr,dp);
        
        int notTake = 0+solve(idx-1,arr,dp);
        
        return dp[idx]=max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        // Approach-1(Memoization Method-top Down Dynamic Programming)
	//    vector<int> dp(n,-1);
    //    int n = nums.size();
	//    return solve(n-1,arr,dp);
	   
	   //Approach-2(Tabulation Method- Bottom up Dynamic Programming Approach)
	   //vector<int> dp(n,-1);
       //int n = nums.size();
	   //dp[0]=nums[0];
	   //for(int i=1;i<n;i++){
	   //    int take = nums[i];
	   //    if(i>1)take+=dp[i-2];
	   //    int notTake = dp[i-1];
	       
	   //    dp[i] = max(take,notTake);
	   //}
	   //return dp[n-1];
	   
	   //Approach-3(Space Optimization Approach)
       int n = nums.size();
	   int prev1 = nums[0];
	   int prev2 = 0;
	   for(int i=1;i<n;i++){
	       int take = nums[i];
	       if(i>1)take+=prev2;
	       
	       int notTake = prev1;
	       
	       int curr = max(take,notTake);
	       prev2 = prev1;
	       prev1 = curr;
	   }
	   return prev1;
    }
};