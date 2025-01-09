class Solution {
public:
    int solve(int idx, vector<int>& points, vector<int>& dp){
        if(idx<=0)return 0;
        if(dp[idx]!=-1)return dp[idx];

        //Take
        int take=points[idx]+solve(idx-2,points,dp);

        //Not-Take
        int not_take=solve(idx-1,points,dp);

        return dp[idx]=max(take,not_take);
    }
    int deleteAndEarn(vector<int>& nums) {
       //Approach-1(Recursion backtracking)
       int n=nums.size();
       int maxi=*max_element(nums.begin(),nums.end());

       vector<int> points(maxi+1,0);

       for(auto it:nums){
        points[it]+=it;
       } 
       
       vector<int> dp(maxi+1,-1);
       return solve(maxi,points,dp);
    }
};